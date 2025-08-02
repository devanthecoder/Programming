`include "quadadder.v"
`timescale 1ns/1ns
module quadadder_tb;
  reg [3:0] A,B;
  wire [3:0] Sum;
  wire Overflow;
  quadadder adn(.A(A),.B(B),.Sum(Sum),.Overflow(Overflow));
  initial begin
    $dumpfile("quadadder.vcd");
    $dumpvars(0,quadadder_tb);
    $monitor("At time t = %t ns, A = %b, B = %b, Sum = %b, Overflow = %b",$time,A,B,Sum,Overflow);
    A = 1; B = 2; #20;
    A = 7; B = 1; #20;
    A = 15; B = 1; #20;
    A = 0; B = 0; #20;
    A = 15; B = 15; #20;
    A = 5; B = 2; #20;
    A = 8; B = 8; #20;
    A = 2; B = 3; #20;
    A = 10; B = 5; #20;
    A = 14; B = 1; #20;
    $finish;
  end
endmodule
