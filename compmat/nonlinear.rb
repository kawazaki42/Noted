# Вариант 4


module NonLinear
  DEFAULT_PRECISION = 1e-6

  module Test
    # Всегда возрастает.
    def self.f x
      x + 2**x + 5
    end

    def self.df x
      1 + Math.log(2) * 2**x
    end

    def self.ddf x
      Math.log(2)**2 * 2**x
    end

    # Всегда возрастает.
    def self.g x
      3 * x**3 + x**2 + 2*x + 3
    end

    def self.dg x
      9 * x**2 + 2*x + 2
    end

    def self.ddg x
      18*x + 2
    end

    def self.report(solver)
      solver.each_with_index.find { |c, i|
        # pp solver.delta
        solver.delta < DEFAULT_PRECISION
      }.then { |c, i|
        puts "f(%f) = %f" % [c, solver.fun.(c)]
        puts "Кол-во итераций: #{i}"
      }
    end

    def self.main
      hf = HalfDivisionSolver.new(method(:f), -10r..10r)
      hg = HalfDivisionSolver.new(method(:g), -10r..10r)

      # плохо работают с дробями (Rational), используем обычные Float'ы
      cf = ChordSolver.new(method(:f), -10.0..10.0)
      cg = ChordSolver.new(method(:g), -10.0..10.0)

      tf = TangentSolver.new(method(:f), -10r..10r, method(:df), method(:ddf))
      tg = TangentSolver.new(method(:g), -10r..10r, method(:dg), method(:ddg))

      puts "Метод половинного деления"
      puts "==="
      report(hf)
      report(hg)

      puts

      puts "Метод хорд"
      puts "==="
      # binding.irb
      report(cf)
      report(cg)

      puts

      puts "Метод касательных"
      puts "==="
      # binding.irb
      report(tf)
      report(tg)

      # solvers = [hf]
      # solvers.each do |s|
      # end
    end
  end


  class IntervalSolver
    include Enumerable

    attr_reader :fun, :begin, :end

    def initialize(fun, range)
      @fun = fun
      @begin = range.begin
      @end = range.end
      @old_value = Float::INFINITY

      fail "В диапазоне нет корня" if @fun.(@begin) * @fun.(@end) >= 0
    end

    def step
      a = @begin
      b = @end
      c = @old_value = value

      root_in_ac = @fun.(a) * @fun.(c) < 0
      root_in_cb = @fun.(c) * @fun.(b) < 0

      @end = c if root_in_ac
      @begin = c if root_in_cb

      value
    end

    def delta
      # return Float::INFINITY unless @old_value
      # return 10 unless @old_value
      (value - @old_value).abs
    end

    def each
      yield value
      loop do
        yield step
      end

      self
    end
  end


  class HalfDivisionSolver < IntervalSolver
    def value
      (@begin + @end)/2
    end

    alias center value

    # def delta
    #   ((@begin - @end)/2).abs
    # end

    # alias delta precision
  end


  class ChordSolver < IntervalSolver
    def value
      a = @begin
      b = @end

      c = a * @fun.(b) - b * @fun.(a)
      c /= @fun.(b) - @fun.(a)
      c
    end

    # def initialize(*args, **kwargs)
    #   super
    #   @old_value = value
    # end

    # def step
    #   @old_value = value
    #   super
    # end

    # def delta
    #   return Float::INFINITY unless @old_value
    #   # return 10 unless @old_value
    #   (value - @old_value).abs
    # end
  end


  class TangentSolver < IntervalSolver
    def initialize(f, range, df, ddf)
      super(f, range)
      @der1 = df
      @der2 = ddf
    end

    def value
      z = if @fun.(@begin) * @der2.(@begin) >= 0 then
        @begin
      elsif @fun.(@end) * @der2.(@end) >= 0 then
        @end
      else
        fail
      end

      z - @fun.(z)/@der1.(z)
    end
  end
end
