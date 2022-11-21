# OS-Lab-2
A demonstration of the Banker's Algorithm for deadlock avoidance.
## About <a name = "about"></a>
Considering a system with five processes P0 through P4 and three resources of type A, B, C. Resource type A has 10 instances, B has 5 instances and type C has 7 instances. Suppose at time t0 following snapshot of the system has been taken:



Implement the Banker’s algorithm to answer the following question：Is the system in a safe state? If Yes, then what is the safe sequence?

## Getting Started <a name = "getting_started"></a>
These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisites
gcc library.
Compiled in Ubuntu 22.04.1

Test for gcc version
```
gcc --version
```
Installing gcc if not already installed
```
sudo apt update
sudo apt install build-essential
```
Confirming gcc installation
```
gcc --version
```
Additionally, <a href="https://github.blog/2020-12-15-token-authentication-requirements-for-git-operations">as of August 13, 2021, password authentication is no longer supported</a>.  This means that you must either <a href="https://docs.github.com/en/authentication/keeping-your-account-and-data-secure/creating-a-personal-access-token">create a personal access token</a> for use with HTML, use an OAuth or GitHub App installation token, or use an SSH Key.

### Installing
1. Clone the Repository

```
git clone https://github.com/Kojavoh/OS-Lab-2.git
```
2. Compile and run the program

```
gcc banker.c -lrt -o banker
./banker
```
3. Exit the program after receiving results

```
Type ^C or Enter
```

## Usage <a name="usage"></a>
This project is an implementation of the Banker's Algorithm for deadlock avoidance.

### Example Output

![Example Output](https://user-images.githubusercontent.com/114598688/199409155-e43b9155-89ab-4b95-a307-fa93b4e62f05.png)
