#ifndef _IDT_H_
#define _IDT_H_

extern void idt_load(unsigned int);
void idt_set_gate(unsigned char num, unsigned long base, unsigned short sel, unsigned char flags);
void idt_install();

#endif