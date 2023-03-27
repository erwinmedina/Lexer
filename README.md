# Assignment 1 - Lexer/Scanner

## Objective:
To create a lexical analyzer that involves parsing the given character stream from an input file. The final product is an output file with all lexemes separated into tokens.

## How To:
- This code was written in C++, and uses a build.sh file in order to run.
- Type `chmod +x build.sh` in the terminal/command prompt, allowing executable permissions.
- Type `./build.sh` in the terminal/command prompt to run the program.
- If you're having difficulties, contact me.

## Programmer/Developer:
Name | Email
---- | -----
Erwin Medina | emedina@csu.fullerton.edu

## Course Info:
Course # | Course Name | Section | Professor
-------- | ----------- | ------- | ----------
CS-323 | Compilers & Languages | 03 | Susmitha Padda

## Results / Screenshots

![Input](https://i.imgur.com/Z6zElWg.png)
---
![Output](https://i.imgur.com/vElWkKK.png)

## Pluses / Minuses
✅ Pluses | ❌ Minuses
------ | -------
Completes objective. | Can't catch _EVERY_ keyword/operator. Needs better database for that.
Parses through input file. | Slightly redundant with catch/try; implement better solution.
Ignores comments + line breaks. | Not designed for duplicate/back-to-back chars [e.g. "==" or "//"].
Tokenizes every lexeme. | Doesn't handle text in strings [e.g. "Hello there"].