# [42] ft_openssl

This repository will hold the entire cryptography branch in the 42 Cadet curriculum. The recreation of various OpenSSL commands are divided into 3 projects, which can be categorized under standard commands, message digest commands, and cipher commands. This branch is good practice for memory and bitwise manipulations.

### Possible Optimization

This group of projects currently assumes that the system they are being ran on is little endian. Being able to check and account for both would be a plus. Due to norm, loops are needed to handle the rounds for hashing instead of being able to write out every line, resulting in unnecessary calculations. The biggest optimization would be to restructure the code in a way that is slightly more modular.

## Final Score

ft_ssl_md5 - 125/100  
ft_ssl_des - In Progress  
ft_ssl_rsa - In Progress  

## Usage

### Compilation

Compiler:

```
clang-6.0
```

Dependencies:

```
libft
```

### Execution

How to run:

```
./ft_ssl [command] [flags] [files]
```

Flags:

```
-p          : hashes standard input.
-q          : quiet mode. Only outputs the hash.
-r          : reverse. Outputs name of file after hash.
-s [string] : hashes the argument as a string instead of a file.
```

Working Commands:

```
Standard Commands:

Message Digest Commands:
md5
sha224
sha256
sha384
sha512

Cipher Commands:

```

## Example

```
./ft_ssl md5 author
MD5(author) = aa5dc97ea60454424cfacb44928f67b2
```

## Norme

This project is coded in accordance with the school's norms. A full copy of the norm can be found [here](https://github.com/MagicHatJo/-42-Norm/blob/master/norme.en.pdf).
