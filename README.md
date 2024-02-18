# Assignment: Part of the Matrix

## Participants

- **Timelid**: [rosinnii](https://lms.khpi.ucode-connect.study/users/rosinnii)
- **Participant**: [voryshchuk](https://lms.khpi.ucode-connect.study/users/voryshchuk)

## Description

This assignment is to create a program that decodes all valid variants of an encrypted mathematical expression. The program accepts four arguments:

- integer operands: `operand1` and `operand2`
- `operation`
- the result of the mathematical operation `result`

## Implementation

1. Your program must support four mathematical operations: addition `+`, subtraction `-`, multiplication `*`, and division `/`.
2. The operands and the result may contain hidden digits, indicated by the symbol `?`.
3. The program should not output zeros if they are in front of a full number.
4. Additionally, implement error handling such as wrong number of arguments, invalid operation, invalid operands and result.

## Notes

- In the "Act: Basic" section, the program must work only with positive values.
- The program must take into account modulo division in case of Euclidean division.

## Run

### Compilation

```sh
make
```

### Starting the program
```sh
./part_of_the_matrix [operand1] [operation] [operand2] [result]
```

## Examples of use

### Errors

./part_of_the_matrix | cat -e
usage: ./part_of_the_matrix [operand1] [operation] [operand2] [result]$
./part_of_the_matrix "xxx" "+" "?0?" "1?0" | cat -e
Invalid operand: xxx$
./part_of_the_matrix "xxx" "??" "?0?" "1?0" | cat -e
Invalid operation: ??$
./part_of_the_matrix "???" "??" "XXX" "1?0" | cat -e
Invalid operation: ??$

### Results

./part*of_the_matrix "343111" "- " "??????" "32410" | cat -e
343111 - 310701 = 32410$
./part_of_the_matrix "?" "*" "11" "??" | cat -e
0 _ 11 = 0$
1 _ 11 = 11$
2 _ 11 = 22$
3 _ 11 = 33$
4 _ 11 = 44$
5 \_ 11 = 55$
6 _ 11 = 66$
7 _ 11 = 77$
8 \_ 11 = 88$
9 \* 11 = 99$

## Relevance

Compiled as part of the [ucode](https://lms.khpi.ucode-connect.study/) project in collaboration with [CBLWorld](https://lms.khpi.ucode-connect.study/). #ucode #CBLWorld
