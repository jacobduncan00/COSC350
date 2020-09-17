# Save your prompt. Write down exactly how you did it.

export `$PS1 >> prompt.txt`

# Change your prompt so it looks like [COSC350 basecwd]: where "basecwd" means the basename of the current working directory. Write down exactly how you did it.

PS1="[COSC350 \W]"

# Change your prompt to its previous value. Write down exactly how you did it.

Went into the prompt.txt file and copied the value that I saved earlier and then ran this command.
PS1="\s-\v\$ "

or alternatively, I could have sourced by bash profile by doing
`source ~/.bash_profile`
