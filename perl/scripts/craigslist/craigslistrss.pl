#!/usr/bin/perl -w

use strict;

my @url;
for (<DATA>) {
  chomp;
  push @url, $_;
}
my @city = map(substr($_,7,index($_, '.')-7), @url);
my %all;
@all{@city} = @url;

my @qa = qw/honolulu humboldt losangeles miami orangecounty portland sandiego santabarbara seattle sfbay ventura washingtondc vancouver victoria/;

my %queries = ( #"993 Porsche" => "search/cta?query=(1995%7C1996%7C1997%7C1998)+Porsche+911&amp;srchType=T&amp;format=rss",
	       "Sof QA Mgr/Lead" => "search/sof?query=QA+(manager%7Clead%7Csenior%7Csr.)&amp;srchType=T&amp;format=rss",
	       "Eng QA Mgr/Lead" => "search/eng?query=QA+(manager%7Clead%7Csenior%7Csr.)&amp;srchType=T&amp;format=rss");

for (@qa) {
    my $city = $_;
    my $pref = ucfirst substr $city,0,5;
    my $url = $all{$city};

    while (my ($k,$v) = each %queries) {
      my $pair = $url.$v;
      print "\t<outline text=\"$pref $k\" title=\"$pref $k\" type=\"rss\" xmlUrl=\"$pair\" htmlUrl=\"$pair\"/>";
      print "\n";
    }
  }



__DATA__
http://atlanta.craigslist.org/
http://boston.craigslist.org/
http://chicago.craigslist.org/
http://denver.craigslist.org/
http://detroit.craigslist.org/
http://honolulu.craigslist.org/
http://humboldt.craigslist.org/
http://lasvegas.craigslist.org/
http://losangeles.craigslist.org/
http://miami.craigslist.org/
http://minneapolis.craigslist.org/
http://newyork.craigslist.org/
http://orangecounty.craigslist.org/
http://philadelphia.craigslist.org/
http://phoenix.craigslist.org/
http://portland.craigslist.org/
http://raleigh.craigslist.org/
http://sacramento.craigslist.org/
http://sandiego.craigslist.org/
http://santabarbara.craigslist.org/
http://seattle.craigslist.org/
http://sfbay.craigslist.org/
http://ventura.craigslist.org/
http://washingtondc.craigslist.org/
http://calgary.craigslist.ca/
http://edmonton.craigslist.ca/
http://halifax.craigslist.ca/
http://montreal.craigslist.ca/
http://ottawa.craigslist.ca/
http://saskatoon.craigslist.ca/
http://toronto.craigslist.ca/
http://vancouver.craigslist.ca/
http://victoria.craigslist.ca/
http://winnipeg.craigslist.ca/
