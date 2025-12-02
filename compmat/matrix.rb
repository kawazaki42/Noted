module Adhoc

class Matrix
  include Enumerable

  def self.from_space_csv(str, **opts)
    require 'csv'

    default_opts = {
      col_sep: ' ',
      converters: :float,
    }

    opts = default_opts.merge(opts)

    csv = CSV(str, **opts)
    Matrix.new(csv.read)
  end

  # def self.rows(r)
  def initialize(r)
    @rows = r.map(&:dup)
  end

  def self.zero(row_size, column_size = row_size)
    rows = Array.new(row_size) {
        Array.new(column_size, 0)
    }
    new(rows)
  end

  def self.diagonal(size, elem = 1)
    new Array.new(size) do |i|
      Array.new(size) do |j|
        if i == j then
          elem
        else
          0
        end
      end
    end
  end

  def to_a
    @rows.map(&:dup)
  end

  def column_count
    @rows[0].length
  end

  def row_count
    @rows.length
  end

  def square?
    row_count == column_count
  end

  def [](i, j)
    @rows[i][j]
  end

  def []=(i, j, v)
    @rows[i][j] = v
  end

  def column(j)
    if block_given?
      row_count.times do |i|
        yield @rows[i][j]
      end
      self
    else
      Array.new(row_count) {|i| @rows[i][j]}
    end
  end

  def row(i)
    if block_given?
      @rows[i].each { |elem| yield elem }
      self
    else
      @rows[i].dup
    end
  end

  def *(other)
    # fail unless row_count == other.column_count
    fail unless column_count == other.row_count
    a = Array.new(row_count) do |i|
      Array.new(other.column_count) do |j|
        Vector.new(row i).dot Vector.new(other.column j)
      end
    end

    self.class.new a
  end

  def transpose
    self.class.new @rows.transpose
  end

  def each
    @rows.each do |r|
      r.each do |e|
        yield e
      end
    end
  end

  def map!
    @rows.map! do |r|
      r.map! do |e|
        yield e
      end
    end
    self
  end

  def map(&block)
    self.class.new(to_a).map!(&block)
  end

  def round(ndigits = 0)
    map { |e| e.round(ndigits) }
  end

  def -(other)
    # zip(other).map {|a, b| a-b}
    a = Array.new(row_count) do |i|
      Array.new(column_count) do |j|
        self[i, j] - other[i, j]
      end
    end

    self.class.new a
  end
end


class Vector
  include Enumerable

  def initialize(elems)
    @elems = elems
  end

  def inner_product(other)
    # if not other.is_a? Vector
      # fail 'not implemented'
    # end
    fail if size != other.size

    self.zip(other).map {|a, b| a*b}.sum
  end

  alias dot inner_product

  def each(&block)
    if block_given?
      @elems.each(&block)
      self
    else
      to_enum
    end
  end

  def size = @elems.size
end

end  # module Adhoc
