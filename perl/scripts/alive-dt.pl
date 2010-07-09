#!/usr/bin/perl -w

# To run this, just chmod 0755 and ./alive-dt.pl

use strict;
use Term::ANSIColor qw(:constants);
use LWP::UserAgent;

my %conf = ('Access', {'uri', '/management/alive/access', 'box', 'access.auth.dev.dt.ccp.cable.comcast.com',},

	    'Console DS', {'uri', '/cds/management/alive', 'box', 'data.console.dev.dt.ccp.cable.comcast.com',},

	    'Entitlements DS', {'uri', '/eds/management/alive', 'box', 'data.entitlement.dev.dt.ccp.cable.comcast.com',},

	    'Entitlements WS', {'uri', '/ent/management/alive', 'box', 'entitlement.dev.dt.ccp.cable.comcast.com',},

	    'Identity', {'uri', '/idm/management/alive/auth', 'box', 'identity.auth.dev.dt.ccp.cable.comcast.com',},

	    'Ingest', {'uri','/management/alive', 'box','ingest.dev.dt.ccp.cable.comcast.com',},

	    'Ingest Adapter', {'uri', '/adapter/management/alive', 'box', 'adapter.ingest.dev.dt.ccp.cable.comcast.com',},

	    'License WS', {'uri', '/license/management/alive', 'box', 'entitlement.dev.dt.ccp.cable.comcast.com',},

	    'MPS Console', {'uri', '/GetLoginEvent.event', 'box', 'mpxfacade.dev.dt.ccp.cable.comcast.com', 'trimResponseBody' => 1,},

	    'MPX Console', {'uri', '', 'box', 'mpxconsole.dev.dt.ccp.cable.comcast.com', 'trimResponseBody' => 1,},

	    'Publish', {'uri', '/management/alive', 'box', 'publish.dev.dt.ccp.cable.comcast.com',},

	    'Publish DS', {'uri', '/publish/management/alive', 'box', 'data.publish.dev.dt.ccp.cable.comcast.com',},

	    'Registry', {'uri', '/descriptors/registry/registry.txt', 'box', 'data.registry.dev.dt.ccp.cable.comcast.com', 'trimResponseBody' => 1,},

	    'Sharing DS', {'uri', '/sharing/management/alive', 'box', 'data.sharing.dev.dt.ccp.cable.comcast.com'},

	    'Watchfolder', {'uri', '/wf/management/alive', 'box', 'data.watchfolder.dev.dt.ccp.cable.comcast.com',},

	    'Watchfolder Agent 1', {'uri', '/management/alive', 'box', '10.253.96.98:10206',},

	    'Watchfolder Agent 2', {'uri', '/management/alive', 'box', '10.253.96.99:10206',},

	    'Workflow', {'uri', '/workflow/management/alive', 'box', 'data.workflow.dev.dt.ccp.cable.comcast.com',},
	   );

my $fmt = "\r%-22s\t%-12s%s\n";

&printHeader;

my $ua = LWP::UserAgent->new(('agent', 'MyApp/0.1', 'timeout', '10'));
foreach my $svc (sort keys %conf) {
  my $url = $conf{$svc}{'box'}.$conf{$svc}{'uri'};

  my ($code, $body) = doRequest($url);
  if (200 == $code) {
    print sprintf($fmt, $svc,$code,$body) . '-'x80 . "\n\n";
  }
  else {
    print RED sprintf($fmt."%36s%s\n", $svc,$code,$body,"",$url); print RESET '-'x80 . "\n\n";
  }
}


sub doRequest {
  my $req = HTTP::Request->new(GET => "http://" . shift);
  my $res = $ua->request($req);
  ($res->code, justifyContent($res->content));
}


sub justifyContent {
  my $body;
  my $cont = shift;
  $cont =~ s/^\s*//;
  $cont =~ s/\s+$//;
  $cont =~ s/(\t+|\n+)//g;
  $cont =~ s/\s{2,}/ /g;

  my $first++;
  for (split /(.{44})/, $cont) {
    next if $_ =~ /^$/;
    $body .= $first ? "$_\n" : sprintf("%36s%s\n", '', $_);
    $first = 0;
  }
  $body;
}


sub printHeader {
  print '='x80 . "\n";
  my $head = sprintf $fmt, "Service Name", "Status", "Response Body / URL (on failure)";
  print BOLD $head; print RESET;
  print '='x80 . "\n";
}
