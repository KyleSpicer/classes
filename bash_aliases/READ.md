# Bash Aliases

Welcome to the "Bash Aliases" class! In this class, you will learn about the power and flexibility of Bash aliases and how they can enhance your command-line experience. This README provides an overview of the class and instructions for getting started.

## Table of Contents

-[Introduction](#introduction)  
-[Getting Started](#getting-started)  
-[Adding Aliases](#adding-aliases)
  - [Adding a SOURCE alias](#adding-a-source-alias)  
  - [Open/edit your .bash_aliases from anywhere](#openedit-your-bash_aliases-from-anywhere)

-[Simple aliases](#simple-aliases)  
-[Copying files using aliases](#copying-files-using-aliases)  
-[Custom functions with aliases](#custom-functions-with-aliases)

## Introduction

### What is `.bashrc`?

The `.bashrc` file is a script that is executed every time you start an interactive Bash shell. It allows you to customize your shell environment by setting various configurations, environment variables, and defining shell functions. It is typically located in your home directory (`~/.bashrc`).

### What is `.bash_aliases`?

The `.bash_aliases` file is a user-specific script that allows you to define custom aliases for frequently used commands in Bash. Aliases are shortcuts that substitute a longer command with a shorter alias, making it easier and faster to execute common tasks. By using the `.bash_aliases` file, you can organize and manage your custom aliases separately from the main `.bashrc` file.

### Why would you use `.bash_aliases`?

The use of `.bash_aliases` offers several advantages:

- **Simplified command execution:** You can define short and memorable aliases for complex or lengthy commands, saving time and reducing typing errors.
- **Customization and personalization:** `.bash_aliases` allows you to personalize your shell experience by creating aliases that match your workflow and preferences.
- **Easy maintenance:** By separating aliases into the `.bash_aliases` file, you can easily manage and update your aliases without modifying the main `.bashrc` file.

In this class, we will explore the concept of Bash aliases and how they can enhance your command-line experience.

## Getting Started

To get started with creating a .bash_aliases file, follow these steps:

1. Open a terminal and navigate to your root directory.

2. The `.bashrc` file is a hidden file. To view hidden files, enter the command `ls -la` in your terminal.

3. Create a `.bash_aliases` file. If you haven't created this file before, it may not be present in your directory. To create it, simply enter `touch .bash_aliases` in your terminal.

4. Open your `.bash_aliases` file. If you just created it, it will be blank.

5. Now you're ready to add your own aliases and customize your Bash experience!

By following these steps, you'll be able to set up and work with Bash aliases effectively.



## Adding Aliases

To get started with creating and using aliases, follow these steps:

1. Open your `.bash_aliases` file using a text editor. If you haven't created this file yet, refer to the [Getting Started](#getting-started) section for instructions on how to create it.

2. Define your aliases by adding lines in the following format: `alias alias_name='command'`. Replace `alias_name` with the desired name for your alias and `command` with the actual command you want to associate with the alias. 

For example: the alias below will allow you to navigate to your desktop from your current location.
 
`**alias d='cd ~/Desktop'**`
	
3. Save and close the .bash_aliases file.

4. To activate the new aliases, either open a new terminal session or run the command source ~/.bashrc to reload the Bash configuration.

5. Test your aliases by running the alias names you defined. For example, if you created the desktop shortcut, you can run 'd' in your terminal and you'll navigate to your desktop from wherever you are within your file system.

### [Adding a SOURCE alias](#adding-a-source-alias)

Updating your .bash_aliases file is simple, but often times I forget I need to source the file to introduce the changes to my current terminal session. An easy way to remember is to create a new alias for it!

1. Open your `.bash_aliases` file using a text editor. If you haven't created this file yet, refer to the [Getting Started](#getting-started) section for instructions on how to create it.

2. Define your new alias for sourcing your '.bash_aliases' file. Below is the alias I used.

`**alias s='source ~/.bash_aliases'**`

3. Save and close the .bash_aliases file.

4. You will need to manually source your .bash_aliases to invoke the new changes by entering 'source ~/.bash_aliases'

5. Test the source functionality now by opening your bash aliases file, making a change, saving the file, closing it, then simply enter 's' in the terminal. This should now source your changes for you. No need to remember that long source command!

### [Open/edit your .bash_aliases from anywhere](#openedit-your-bash_aliases-from-anywhere)

Opening your '.bash_aliases' to make a quick change shouldn't require any brain power. Let's make an alias that will allow us to enter one command to open our '.bash_aliases' file from anywhere within our file system.

1. Open your `.bash_aliases` file using a text editor. If you haven't created this file yet, refer to the [Getting Started](#getting-started) section for instructions on how to create it.

2. Define your new alias for opening your '.bash_aliases' file. Below is the alias I used.

`**alias gc='gedit ~/.bash_aliases'**`

You can also combine aliases for more power! For example, combining the source alias with the alias to open your '.bash_aliases' file will automatically source the file for you when it closes.

`**alias gc='gedit ~/.bash_aliases; source ~/.bash_aliases;'**`

3. Save and close the '.bash_aliases' file.

4. Source the '.bash_aliases; file to implement the changes.

5. Now you should be able to simply enter 'gc' into your teminal and your '.bash_alises' file will open regardless of your location in your file system.



## [Simple aliases](#simple-aliases)
 - Simple aliases provide an effective means to enhance efficiency by reducing keystrokes. Here are a few illustrative examples along with their descriptions:

1. ```alias hub='cd ~/Desktop/github'```: This alias simplifies navigation. Instead of manually typing the path every time to access a commonly used folder, I have created an alias and added it to my aliases file. Now, regardless of my current location within the file system, executing 'hub' in a terminal promptly takes me to my GitHub folder.

2. ```alias errno='man 3 errno'```: Aliases can be employed to streamline repetitive information retrieval. In scenarios where frequent reference to specific documentation is necessary during project work, I often create aliases to expedite access to the relevant documentation.

3.  ```alias protocols='cat /etc/protocols'```: Furthermore, I create aliases to quickly view the contents of files within my file system for documentation purposes. The provided examples serve to inspire potential ideas for creating aliases that suit individual preferences and requirements.

##  [Copying files using aliases](#copying-files-using-aliases)
- Copying frequently used files such as libraries or skeleton files can also be a massive time saver. Below are a few examples.
### Copying libraries
- In C programming, a library is a collection of precompiled functions and code that can be used by other programs, offering ready-made functionality and promoting code reusability. It simplifies development by providing a range of pre-implemented functions for common tasks.

- I maintain a set of frequently used and regularly updated libraries in a consistent location within my file system. To simplify the process of copying the `".c"` and `".h"` files for each library to my current working directory, I created aliases. One such alias, `"get-file-io"` is designed to copy all the contents from a specified path to my current location, regardless of where I am within the file system.

Alias:  
`alias get-file-io="cp ~/Desktop/github/spice_libraries/c/file_io/* ."`


Implementation:
```
[tester] ❱❱❱  $ get-file-io 
[tester] ❱❱❱  $ ls
file_io.c  file_io.h
```


### Copying skeleton files
- A skeleton file serves as a basic template containing all the necessary required includes and formatting to initiate a program.

- This alias enables the copying of a C skeleton file from a specified path. Once executed, it prompts the user to enter a new name for the file. In the alias, the path and file name are denoted as ```skeleton.c```. When the alias is run, the terminal will display the prompt ```"Enter the new name for the C file:"```. For instance, if the user enters testfile, the alias will copy the ```skeleton.c``` file from the specified path, rename it to ```testfile.c```, and save the copy in the current directory. The implementation can be demonstrated as follows:

Alias:  
`alias get-c-skeleton='cp ~/Desktop/github/spice_libraries/c/skeleton.c "$(read -e -p "Enter new C file name: "; echo "$REPLY".c)"'`

1Implementation:
```
[tester] ❱❱❱  $ get-c-skeleton 
Enter new C file name: testfile
[tester] ❱❱❱  $ ls
testfile.c
```


##  [Custom functions with aliases](#custom-functions-with-aliases)
- Aliases can also be employed to streamline repetitive command line tasks, such as securely copying files from one computer to another using the scp command over SSH. This is particularly useful when working on one computer, as creating an alias for the scp command eliminates the need to manually type out the command each time, enabling swift and convenient file transfers.

```
scp_() {
        scp -P XXXXX -r "$@" your.ip.addr.here:~/Desktop/scp/.
}
```

### Let's break this alias down:
-**alias name** : `scp_` with an underscore added afterward. This naming convention is necessary because the command `scp` already exists. While it might be beneficial to choose a more descriptive name, the current alias serves its purpose effectively.

-**scp command** : the function call is secure copy (`scp`), from port XXXXX (`-P XXXXX`), capture command line argument after function call (`"@"`), and the address and path to copy the files (`your.ip.addr.here:~/Desktop/scp/.`).

- If implemented properly, with the correct privelages, you will be able to simply enter  "`scp_ [filename]`" and the alias will do the rest.

- First time running alias: you will see something similar to this to establish a connection:
```
This host key is known by the following other names/addresses:
    ~/.ssh/known_hosts:15: [hashed name]
Are you sure you want to continue connecting (yes/no/[fingerprint])?
```
- after entering `yes`, this alias will skip this step and just prompt you for your password to continue.

Implementaion:
```
[~] ❱❱❱  $ scp_ testfile.txt
kyle@kdspicer.com's password: 
```
