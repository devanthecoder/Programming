//THIS PROGRAM CONSIDERS UNSIGNED BINARY SYSTEM.
`timescale 1ns/1ns
//Module for 1 ns delay NAND gate
module NAND1(
  input A,B,
  output Y
);
  assign #1 Y = ~(A&B);
endmodule
//Module for 1-BIT FULL ADDER
module bitadder(
  input A,B,Cin,
  output Cout,Sum
);
  wire AnandB,AxorB,w1,w2,AxorBdotC,x1,x2;
  NAND1 one(.A(A),.B(B),.Y(AnandB));
  NAND1 two(.A(A),.B(AnandB),.Y(w1));
  NAND1 three(.A(B),.B(AnandB),.Y(w2));
  NAND1 four(.A(w1),.B(w2),.Y(AxorB));
  NAND1 five(.A(Cin),.B(AxorB),.Y(AxorBdotC));
  NAND1 six(.A(AxorBdotC),.B(AnandB),.Y(Cout));
  NAND1 seven(.A(Cin),.B(AxorBdotC),.Y(x1));
  NAND1 eight(.A(AxorBdotC),.B(AxorB),.Y(x2));
  NAND1 nine(.A(x1),.B(x2),.Y(Sum));
endmodule
//Module for 4-BIT FULL ADDER
module quadadder(
  input [3:0] A,
  input [3:0] B,
  output [3:0] Sum,
  output Overflow
);
  wire C[4:0];
  assign C[0]=0;
  bitadder fulladd1(.A(A[0]),.B(B[0]),.Cin(C[0]),.Cout(C[1]),.Sum(Sum[0]));
  bitadder fulladd2(.A(A[1]),.B(B[1]),.Cin(C[1]),.Cout(C[2]),.Sum(Sum[1]));
  bitadder fulladd3(.A(A[2]),.B(B[2]),.Cin(C[2]),.Cout(C[3]),.Sum(Sum[2]));
  bitadder fulladd4(.A(A[3]),.B(B[3]),.Cin(C[3]),.Cout(C[4]),.Sum(Sum[3]));
  assign Overflow=C[4];
endmodule
