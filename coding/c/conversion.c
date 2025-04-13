
/*
https://www.rapidtables.com/convert/number/binary-to-hex.html?x=101111

binary to decimal:  (101111)₂ = (1 × 2⁵) + (0 × 2⁴) + (1 × 2³) + (1 × 2²) + (1 × 2¹) + (1 × 2⁰) = 47
octal to decimal: 77 = (7 × 8¹) + (7 × 8⁰) = 63
Hex to decimal: (FF)₁₆ = (15 × 16¹) + (15 × 16⁰) = (255)₁₀

binary to octal: input- > 101111; split into 3s -> (101)(111); decimal equivalent-> 57
binary to hex: input- > 101111; split into 4s -> (0010)(1111); decimal equivalent-> Ox2F

decimal to binary: divide by and get reaminder.
Octal to Binary: Convert each octal digit to 3 binary digits: 77 = 7 7 = 111 111 = 111111
Hex to Binary: Convert each hex digit to 4 binary digits: FF = F F = 1111 1111 = 11111111

Octal to hex => octal to binary to hex
hex to octal => hex to binary to octal
*/