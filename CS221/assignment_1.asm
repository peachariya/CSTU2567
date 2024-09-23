.global assign
.text

assign:
    mov $0x1,%rax
    mov $0x1,%r8

loop:
    dec %rax
    jnz loop
    imul %r8,%rax

done:
    ret