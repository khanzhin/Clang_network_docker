FROM ruby

RUN apt-get update -y && apt-get upgrade -y
RUN apt-get install -y nodejs
RUN gem install rails

ONBUILD WORKDIR /opt/app
ONBUILD COPY . /opt/app

ONBUILD RUN bundle install
ONBUILD RUN rails db:migrate
ONBUILD RUN rails db:seed
