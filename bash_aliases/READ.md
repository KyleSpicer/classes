# Bash Aliases

Welcome to the "Bash Aliases" class! In this class, you will learn about the power and flexibility of Bash aliases and how they can enhance your command-line experience. This README provides an overview of the class and instructions for getting started.

## Table of Contents

-[Introduction](#introduction)  
-[Getting Started](#getting-started)  
-[Adding Aliases](#adding-aliases)  



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
 
	**alias d='cd ~/Desktop'**
	
3. Save and close the .bash_aliases file.

4. To activate the new aliases, either open a new terminal session or run the command source ~/.bashrc to reload the Bash configuration.

5. Test your aliases by running the alias names you defined. For example, if you created the desktop shortcut, you can run 'd' in your terminal and you'll navigate to your desktop from wherever you are within your file system.

### Adding a SOURCE alias

Updating your .bash_aliases file is simple, but often times I forget I need to source the file to introduce the changes to my current terminal session. An easy way to remember is to create a new alias for it!

1. Open your `.bash_aliases` file using a text editor. If you haven't created this file yet, refer to the [Getting Started](#getting-started) section for instructions on how to create it.

2. Define your new alias for sourcing your '.bash_aliases' file. Below is the alias I used.

**alias s='source ~/.bash_aliases'**

3. Save and close the .bash_aliases file.

4. You will need to manually source your .bash_aliases to invoke the new changes by entering 'source ~/.bash_aliases'

5. Test the source functionality now by opening your bash aliases file, making a change, saving the file, closing it, then simply enter 's' in the terminal. This should now source your changes for you. No need to remember that long source command!

### Adding an alias to open you .bash_alias from anywhere

Opening your '.bash_aliases' to make a quick change shouldn't require any brain power. Let's make an alias that will allow us to enter one command to open our '.bash_aliases' file from anywhere within our file system.

1. Open your `.bash_aliases` file using a text editor. If you haven't created this file yet, refer to the [Getting Started](#getting-started) section for instructions on how to create it.

2. Define your new alias for opening your '.bash_aliases' file. Below is the alias I used.

**alias gc='gedit ~/.bash_aliases'**

You can also combine aliases for more power! For example, combining the source alias with the alias to open your '.bash_aliases' file will automatically source the file for you when it closes.

**alias gc='gedit ~/.bash_aliases; source ~/.bash_aliases;'**

3. Save and close the '.bash_aliases' file.

4. Source the '.bash_aliases; file to implement the changes.

5. Now you should be able to simply enter 'gc' into your teminal and your '.bash_alises' file will open regardless of your location in your file system.
