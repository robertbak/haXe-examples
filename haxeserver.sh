#!/bin/bash
haxe compileServer.hxml
nekotools server -p 2000 -h localhost -d ./bin/neko/ -log logfile.txt
