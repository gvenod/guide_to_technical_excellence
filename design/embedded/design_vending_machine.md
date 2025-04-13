#design a product vending machine

##FR:
select , pay, dispense.

##finite state machine:

idle -> select/confirm -> pay -> dispense -> idle
	cancel/timeout - idle
			payment failure -> idle

##non FR:
 handle edge cases - wrong code
 atomic - payment + dispense
 inventory check
 proper error display

##assumptions: 
	- single item at a time, 
	- user verifies the inventory - not null
	- code for every product
 	- price mentioned at code.
	- full prize and coins used

##Approach/Flow:
	services - decoupled via event queue.
	post event for services to act.

##Data model:
code, product qty price
B25, xyz, 2, 2.50

product - serial - status - modified time.
xyz - 001 - new- 1.00
xyz - 002 - dispatched - 12.00


				
##HLD:
button click:
selection service - API /picked {product - code}
	update event Q [handle payment - code]
payment service - API /handlePayment {code}
	- 1. wait for money 
	- 2. check
	- if more(return extra)
	- if less (go to 1)
	- if paid return success
	- if timeout - give money back and return failure;
	- update event Q [code - paid]
dispenser service.
	- trigger motor to dispense item
	- update event Q [item dispatched success/failure - failure - reach out to csutomer care for reembursiement; mention transaction id: ]
	- refund.......
		