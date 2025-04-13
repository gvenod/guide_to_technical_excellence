
defined test template
	- junit  
 - hook


Test Case
Test Runner
Test Suite
Test Fixture
Assertions
Annotations


The TDD culture lays strong emphasis on setting up the test data for testing a logic that would be implemented once the testing is successful. 

Mocking is a phenomenon where an object mimics a real object. 

Stubbing are the codes responsible for taking place of another component. 

Assert methods are utility methods that support assert conditions in test cases. 
assertEquals(): This method compares 2 objects for equality by making use of the equals() method of the object.
assertTrue(): This method tests whether the value of a variable is true.
assertFalse(): This method tests whether the value of a variable is false.


For calling test methods, JUnit creates separate individual instances of the test class. For example, if the test class contains 10 tests, then JUnit creates 10 instances of the class to execute the test methods. In this way, every test is isolated from the other.