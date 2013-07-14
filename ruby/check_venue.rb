#!/usr/bin/env ruby

require 'foursquare2'
require './credentials.rb'

VENUE_ID      = '50bb38eb45b068a260dfa032'

client = Foursquare2::Client.new(:client_id => CLIENT_ID, :client_secret => CLIENT_SECRET)
old_count = client.herenow(VENUE_ID).hereNow[:count]
puts "Initially we have #{old_count} people here..."

while(true)
  new_count = client.herenow(VENUE_ID).hereNow[:count]
  puts "Change detected - now there are #{new_count} people at the venue." if new_count != old_count
  old_count = new_count
  sleep 1
end