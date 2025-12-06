# Вариант 4


module NonLinear
  DEFAULT_PRECISION = 1e-6

  module Test
    
    # Всегда возрастает.
    def self.f x
      x + 2**x + 5
    end

    def self.df x
      1 + Math.ln(2) * 2**x
    end

    # Всегда возрастает.
    def self.g x
      3 * x**3 + x**2 + 2*x + 3
    end

    def self.dg x
      9 * x**2 + 2*x + 2
    end

    def self.main
      h = HalfDivisionSolver.new(method(:f), -10r..10r)

      h.each_with_index.find { |c, i|
        h.delta < DEFAULT_PRECISION
      }.then { |c, i|
        puts "f(%f) = %f" % [c, f(c)]
        puts "Кол-во итераций: #{i}"
      }
    end
  end

  class IntervalSolver
    include Enumerable

    def initialize(fun, range)
      @fun = fun
      @begin = range.begin
      @end = range.end

      fail "В диапазоне нет корня" if @fun.(@begin) * @fun.(@end) >= 0
    end

    def each
      yield value
      loop do
        yield step
      end

      self
    end

    def value
      (@begin + @end)/2
    end

    alias center value

    def precision
      ((@begin - @end)/2).abs
    end

    alias delta precision
  end


  class HalfDivisionSolver < IntervalSolver
    def step
      a = @begin
      b = @end
      c = center

      root_in_ac = @fun.(a) * @fun.(c) < 0
      root_in_cb = @fun.(c) * @fun.(b) < 0

      @end = c if root_in_ac
      @begin = c if root_in_cb

      center
    end
  end
end
