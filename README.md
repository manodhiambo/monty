           0x19. C - Stacks, Queues - LIFO, FIFO

	   Resources

             Read or watch:

   .Google

   .How do I use extern to share variables between source files in C?

   .Learning Objectives

   .At the end of this project, you are expected to be able to explain to anyone, without the help of Google:

               General

   .What do LIFO and FIFO mean

   .What is a stack, and when to use it

   .What is a queue, and when to use it

   .What are the common implementations of stacks and queues

   .What are the most common use cases of stacks and queues

   .What is the proper way to use global variables

        The Monty language
	
  .Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). 
  .It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

         Monty byte code files

  .Files containing Monty byte codes usually have the .m extension.   .Most of the industry uses this standard but it is not required by the specification of the language. 
  .There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:
  .Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account:
