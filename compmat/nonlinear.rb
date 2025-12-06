# Вариант 4


module NonLinear
  DEFAULT_PRECISION = 1e-6

  module Test
    
    def self.f x
      # Всегда возрастает.
      x + 2**x + 5
    end

    def self.df x
      1 + Math.ln(2) * 2**x
    end

    def self.g x
      # Всегда возрастает.
      3 * x**3 + x**2 + 2*x + 3
    end

    def self.dg x
      9 * x**2 + 2*x + 2
    end

    def self.main
      # NonLinear.half(method(:f), -10r..10r)
      #   .each_with_index.find { |(a, b), idx|
      #     (a-b).abs < 2*DEFAULT_PRECISION
      #   }.then { |(a, b), idx|
      #     [(a+b)/2, idx + 1]
      #   }.then { |c, itercount|
      #     puts "f(#{c.to_f}) = #{f(c)}"
      #     puts "Кол-во итераций: #{itercount}"
      #   }

      h = HalfDivisionSolver.new(method(:f), -10r..10r)
      h.each_with_index.find { |c, i|
        h.delta < DEFAULT_PRECISION
      }.then { |c, i|
        puts "f(#{c.to_f}) = #{f(c)}"
        puts "Кол-во итераций: #{i}"
      }
    end
  end

  # def self.step_half((a, b, fn))
  #   c = (a+b)/2

  #   root_in_ac = fn.(a) * fn.(c) < 0
  #   root_in_cb = fn.(c) * fn.(b) < 0

  #   b = c if root_in_ac
  #   a = c if root_in_cb

  #   [a, b, fn]
  # end

  # def self.step_half a, b
  #   Enumerator.new do
  #     while 
  #   end
  # end

  # def self.half(fn, range, precision = DEFAULT_PRECISION, count_iters: false)
  # def self.half(fn, range)
  #   a, b = range.begin, range.end
  #   fail "В диапазоне нет корня" if fn.(a) * fn.(b) >= 0

  #   Enumerator.produce [a, b, fn], &method(:step_half).to_proc

  #   # itercount = 0

  #   # a, b = e.find { |a, b|
  #   #   itercount += 1
  #   #   (a-b).abs < 2*precision
  #   # }

  #   # (a+b)/2
  # end

  class IntervalSolver
    include Enumerable

    def initialize(fun, range)
      @fun = fun
      @begin = range.begin
      @end = range.end

      fail "В диапазоне нет корня" if @fun.(@begin) * @fun.(@end) >= 0
    end

    def each
      # binding.irb
      # a, b = @begin, @end

      yield value
      loop do
        yield step
        # yield self
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
