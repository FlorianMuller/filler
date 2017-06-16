# ./../filler_vm -f ../maps/map01 -p2 ../fmuller.filler -p1 ../players/carli.filler >&coolpipe &
# ./backToTheFiller

# ./../filler_vm -f ../maps/map01 -p2 ../fmuller.filler -p1 ../players/carli.filler >&coolpipe &  ./backToTheFiller

$@ >&coolpipe & ./backToTheFiller