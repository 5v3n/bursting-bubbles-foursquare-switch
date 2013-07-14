require 'sinatra'
require 'json'
require 'haml'
require 'rack/logger'
require 'foursquare2'
require_relative 'credentials.rb'

class RatPackServer < Sinatra::Application
  VENUE_ID        = '50bb38eb45b068a260dfa032'
  CLIENT_ID       ||= ENV['FOURSQAURE_CLIENT_ID']
  CLIENT_SECRET   ||= ENV['FOURSQAURE_CLIENT_SECRET']


  configure()             { set :activated, 0 }
  configure()             { set :people_count, 0 }
  configure(:development) { set :logging, Logger::DEBUG }
  configure(:production)  { set :logging, Logger::INFO }
  configure(:test)        { disable :logging }
 
  get '/status.json' do
    render_status_response
  end
private
  def people_count_changed?()
    changed = 0
    old_count = settings.people_count
    client = Foursquare2::Client.new(:client_id => CLIENT_ID, :client_secret => CLIENT_SECRET)
    settings.people_count = client.herenow(VENUE_ID).hereNow[:count]
    if old_count != settings.people_count
      changed = 1
      logger.info "Change detected - now there are #{settings.people_count} people at the venue."
    end
    changed
  end
  def render_status_response
    settings.activated = people_count_changed?
    {activated: settings.activated, people_count: settings.people_count}.to_json
  end
end