
design ticker master

user stories:
	user search and get list of event/artist/location/time/price 
	user select the options & pick seats [half block here] and press pay.
	seats blocked [timer started] - DB updated notified all other user views....
	user pay within time limit.
	seats marked unavailable & tickets generated....

FR: 
	search & view events/check seat availabity 
	issue available tickets [reserve seat]
	process payment
	Algo: grouping of tickets
	cancel
	reserve/block for 5 mintues while payment is processed.

Non FR:
	atomic
	ux
	secure
	consistence for booking
	availabiltiy for searching
	error handling / check later 


HLD:
	DB
		event table: event by date, venue/location, genre, artist....
		ticket table: seat - status - prize - ticket id group 
		
		


	

	

