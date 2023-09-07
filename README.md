# proxytest
informal performance testing code for smrproxy and arcproxy

This is quick and dirty code to do informal performance testing of smrproxy and arcproxy.
The smrproxy and arcproxy repos should be checked out in the parent directory and cmake . and make install done on both.

The default count is kind of low for smr and arc.  Count should be set to 10 million or more to get reasonable timings without
scheduler artifacts affecting them.
