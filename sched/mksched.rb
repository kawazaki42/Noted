require 'nokogiri'


File.open("source.html") do |f|
  doc = Nokogiri::HTML(f)
  # rows = doc.css("table tr [rowspan]")
  # table = doc.at_css("table").children.reject(&:text?)
  cells = doc.css("table td")
  # header, *rest = rows
  # p header.map(&:text).map(&:strip)
  # p rows.text.gsub(/\s+/, ' ')
  # rows.each {
  #   p it.children.reject(&:text?).first
  # }
  # rows.each {
  #   p it.text.gsub(/\s+/, ' ')
  # }
  # p rows[1]
  # p rows
  # p rows.length
  # cells = rows.css("td[rowspan]")
  # p cells.length
  # cells.each {
  #   p it[:rowspan]
  # }
  # p table.length
  # table.each {
  #   p it.name
  # }
  
end
