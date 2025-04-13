
class vechicle
  - type {tiny(bikes),s (compact), m, l, xl (bus/truck)}
  - rate {initial/every 30 min - map : type:$ }
  - slot {mapping: car model by type}
  - license plate
  scan_license plate()
  generate_type() {
	length of vechile > x && width of the vechile > y
	return type	
  }
  
  
Class payment
  - 
  
Class User
	- entry
	- exit
	- Vechile vDetails
	- payment payDetails 
		
ticket_controller_service:
   - always on camera - analyzing frame for vechile object
   - generate event when camera detects vechile in frame.
   - pub/sub - topic new_vechile_detected
   - scanner service: - collects license plate, type 
   - pub/sub - topic type_detected
   - ask slot service for available slots based on type. get slot number.
   - pub/sub - topic slot_available
   - payment service: get payment details - check validity .....
   - pub/sub - topic payment_Verified
   - manager service: entry into database: entry, 
   - pub/sub - topic Entry_allowed
   