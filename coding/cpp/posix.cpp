
/*
C++ programs can interact with external processes using functions like system or by creating pipes and using fork and exec. This allows for communication with other programs and utilization of their functionalities.
*/

#include <iostream>
#include <unistd.h> //fork
#include <sys/types.h>
#include <sys/wait.h>
#include <cstdlib> //system
#include <thread>
#include <mutex>

std::mutex m;
int i = 0;

void makeACallFromPhoneBooth() 
{
    m.lock();//man gets a hold of the phone booth door and locks it. The other men wait outside
      
      std::cout << i << " Hello ....." << std::endl;
      i++;//no other thread can access variable i until m.unlock() is called
      //...until now, with no interruption from other men

    m.unlock();//man lets go of the door handle and unlocks the door
}

int main() {
	
  int result = system("date");
  if (result == -1) {
    perror("system");
    return 1;
  }
  std::cout << "Command executed with result: " << result << std::endl;
  
  std::thread man1(makeACallFromPhoneBooth);
  std::thread man2(makeACallFromPhoneBooth);
  man1.join();
  man2.join();
  
  pid_t pid = fork();
  if (pid == 0) {
    // Child process
    execl("/bin/ls", "ls", "-l", nullptr);
    perror("execl"); // Executed only if execl fails
    return 1;
  } else if (pid > 0) {
    // Parent process
    int status;
    waitpid(pid, &status, 0);
    std::cout << "Child process exited with status: " << status << std::endl;
  } else {
    // Fork error
    perror("fork");
    return 1;
  }
  return 0;
}