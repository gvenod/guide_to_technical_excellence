
#design a coffee vending machine.

##clarify:
 payment required or free
 ingredient/item availability - infinite vs constrained
 cup & size detection
 no of users? will it matter?
 only one order at a time
 no update to the order. - cancel and start new_task
 notification/alert mechanism

##concept:
  -> selection [item, size, temp] -> check [item quantity, cup size] -> payment -> vending
  -> notify on refill required/out of order error
  
##blocks
	//all decoupled services interacts through message queue.
	user interaction - UI service [producer - id: new_task]  ->push to queue [all params]
	[consumer]controller service - pick it up over all control - policy matching [producer - id: verify] 
	[consumer] vending service - verify quantity, cup presense, size match.... [producer - id: vending_ready]
	[consumer] payment service [producer: -id: payment_status[success_failure]]
	[consumer]controller service [producer: id: cancel_all/vend]
	[consumer]vending service - success	
	[consumer]UI service - error/success.
	[consumer]controller service - cleanup activity.
  
##API & data flow:
	-> /add {item, size, tmep ....}
	-> /pay {details}
	-> /cancel [current]
	
##assumptions


##possible errors

##onstart, power savings, time of use; 
 
 
 
  
  

