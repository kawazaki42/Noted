require_relative 'matrix.rb'

module QR
  TESTS = [
    <<~EOF,
      9 8 1 4 9
      6 5 5 2 9
      5 7 9 9 1
      6 8 2 1 3
      6 8 9 9 2
    EOF

    <<~EOF,
      1 6 8
      2 4 7
      1 1 3
    EOF

    <<~EOF,
      2 2 2 1 2
      2 0 2 1 1
      1 0 1 1 0
      1 0 2 2 2
      1 0 0 2 2
    EOF

    <<~EOF,
      2 0 0 1 0
      3 3 1 1 2
      1 0 0 2 2
      1 0 0 2 0
      0 0 1 2 1
    EOF
  ].map{ |str| Adhoc::Matrix.from_space_csv(str, converters: proc { |elem| Rational elem}) }

  # TEST_PRIMARY = Adhoc::Matrix.from_space_csv <<~EOF

  # TEST1 = Adhoc::Matrix.from_space_csv <<~EOF
  #   2 2 2 1 2
  #   2 0 2 1 1
  #   1 0 1 1 0
  #   1 0 2 2 2
  #   1 0 0 2 2
  # EOF

  # TEST2 = Adhoc::Matrix.from_space_csv 

  # TEST_PRIMARY.freeze
  # TEST1.freeze

  TESTS.freeze

  def self.decompose(matrix)
    fail unless matrix.square?

    order = matrix.row_count

    q = Adhoc::Matrix.new(matrix.to_a)
    r = Adhoc::Matrix.zero(order)

    order.times do |j|
      r[j, j] = q.column(j).map { it**2 }.sum.then { Math.sqrt it }
      order.times do |i|
        q[i, j] /= r[j, j]
      end
      (j+1...order).each do |k|
        a = q.column j
        b = q.column k

        # a.zip(b).map {|x, y| x * y}.sum
        r[j, k] = Adhoc::Vector::new(a).dot(b)

        order.times do |i|
          q[i, k] -= q[i,j] * r[j,k]
        end

        # order.times do |i|
          # q[i, k] -= q[i, j] * r[j, k]
        # end
      end
    end

    order.times do |i|
      order.times do |j|
        # if j < i and r[i, j] >= 1e-6
        if j < i and r[i, j] != 0
          fail "not upper triangular"
        end
      end
    end

    return q, r
  end

  def self.test(id = 0)
    # q, r = decompose TEST

    # pp q.round 2
    # pp r.round 2

    # pp (q.transpose * q).round 2

    # pp (q * r).round 2

    a = TESTS[id]

    puts "a = "
    pp a

    # case id
    # when 0
    #   a = TEST_PRIMARY
    # when 1
    #   a = TEST1
    # when 2
    #   a = TEST2
    # end

    q, r = decompose a
    # puts "q * r = "
    # pp q * r
    
    puts "q * r - a = "
    pp q * r - a

    id = Adhoc::Matrix.diagonal(a.row_count)
    300.times do
      q, r = decompose a
      # q = q.round 6
      # r = r.round 6
      # pp q.transpose * q
      # pp Adhoc::Matrix.diagonal(a.row_count)
      # pp q.transpose * q - Adhoc::Matrix.diagonal(a.row_count)
      # pp q.transpose * q
      (q*r - a).round(2).each { |elem|
        fail if not elem.zero?
      }
        # .then { pp it }
      (q * q.transpose - id).round(2).each do |elem|
        fail if not elem.zero?
      end
        # .then {pp it}
      a = r * q
      a = a.round(6)
    end

    pp a.round 2

    fail unless a.square?
    order = a.row_count

    result = Array.new(order) do |i|
      # binding.irb
      if i+1 < order and a[i+1, i] >= 1e-6
        nil
      elsif (i >= 1) and (a[i, i-1] >= 1e-6)
        nil
      else
        a[i,i]
      end
    end

    p result
  end
end
