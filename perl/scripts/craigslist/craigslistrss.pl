#!/usr/bin/perl -w

use strict;
my %all;
for (<DATA>) {
  chomp;
  $all{substr($_,7,index($_, '.')-7)} = $_;
}
my @allcity = sort keys %all;

my @qacity = qw/honolulu humboldt losangeles miami orangecounty portland sandiego santabarbara seattle sfbay ventura washingtondc vancouver victoria/;

my %queries = ('invest' => {'Invest' => 'search/?query=investor&amp;catAbb=sss&amp;format=rss'},
	       '911' => {'993 Porsche' => 'search/cta?query=(1995%7C1996%7C1997%7C1998)+Porsche+911&amp;srchType=T&amp;format=rss'},
	       'qa' => {'Sof QA Mgr/Lead' => 'search/sof?query=QA+(manager%7Clead%7Csenior%7Csr.)&amp;srchType=T&amp;format=rss',
			'Eng QA Mgr/Lead' => 'search/eng?query=QA+(manager%7Clead%7Csenior%7Csr.)&amp;srchType=T&amp;format=rss'},);

my ($where, $what) = (0,0);

if ($ARGV[0] =~ /qa/) {
  ($where, $what) = (\@qacity, $queries{'qa'});
} elsif ($ARGV[0] =~ /911/) {
  ($where, $what) = (\@allcity, $queries{'911'});
} elsif ($ARGV[0] =~ /invest/) {
  ($where, $what) = (\@allcity, $queries{'invest'});
}

if (0 != $where && 0 != $what) {

  &header();

  for (@{$where}) {
    my $city = $_;
    my $pref = ucfirst substr $city,0,5;
    my $url = $all{$city};

    while (my ($k,$v) = each %{$what}) {
      my $pair = $url.$v;
      print "\t<outline text=\"$pref $k\" title=\"$pref $k\" type=\"rss\" xmlUrl=\"$pair\" htmlUrl=\"$pair\"/>";
      print "\n";
    }
  }

  &footer();
}

sub header {
print '<?xml version="1.0" encoding="UTF-8"?>
<opml version="1.0">
    <head>
        <title>cacci subscriptions in Google Reader</title>
    </head>
    <body>
'
}

sub footer {
  print '    </body>
</opml>
'
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
