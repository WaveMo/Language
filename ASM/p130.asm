assume cs:code, ds:data, ss:stack

data segment
    dw 0123h, 0456h, 0789h, 0abch, 0defh, 0fedh, 0cbah, 0987h
data ends

stack segment
    dw 0, 0, 0, 0, 0, 0, 0, 0
stack ends

code segment
start: mov ax, stack
       mov ss, ax
       mov sp, 20h      ;����ջ������ss:spָ��stack��20

       mov ax, data
       mov ds, ax       ;dsָ��data��

       mov bx, 0        ;ds:bxָ��data���еĵ�һ����Ԫ

       mov cx, 8
    s: push [bx]
       add ba, 2
       loop s           ;���Ͻ�data���е�0~15��Ԫ�е�8����������������ջ

       mov bx, 0

       mov cx, 8
   s0: pop [bx]
       add bx, 2
       loop s0          ;��ջ

       mov ax, 4c00h
       int 21h
code ends
end start
