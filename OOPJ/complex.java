import java.util.Scanner;
class ComplexNumber{
    float real;
    float imaginary;
    ComplexNumber(float x , float y){
        real = x;
        imaginary = y;
        print();
    }
    ComplexNumber(){
       getData();
       print();
    }
    void getData(){
         Scanner in = new Scanner(System.in);
         System.out.println("Enter the real part of second complex number : ");
         real = in.nextFloat();
         System.out.println("Enter the Imaginary part of second complex number : ");
         imaginary = in.nextFloat();
    }
    void print(){
        System.out.println("The complex number is "+ real + " + "+ imaginary + " i ");
    }
    void add(ComplexNumber obj1,ComplexNumber obj2 ){
        float a = obj1.real + obj2.real;
        float b = obj1.imaginary + obj2.imaginary;
        System.out.println("The addition of complex number is "+ a + " + "+ b + " i ");
    }
    void sub(ComplexNumber obj1,ComplexNumber obj2 ){
        float a = obj1.real - obj2.real;
        float b = obj1.imaginary - obj2.imaginary;
        System.out.println("The subtraction of complex number is "+ a + " + "+ b + " i ");
    }
    void mul(ComplexNumber obj1 , ComplexNumber obj2){
        float a = obj1.real * obj2.real - obj1.imaginary * obj2.imaginary;
        float b = obj1.real * obj2.imaginary + obj1.imaginary * obj2.real;
         System.out.println("The multiplication of complex number is "+ a + " + "+ b + " i ");
    }
    void divide(ComplexNumber obj1,ComplexNumber obj2){
        float a = obj1.real;
        float b = obj1.imaginary;
        float c = obj2.real;
        float d = obj2.imaginary;
        float denominator = (c *c) + (d * d);
        float real = ((a*c)+(b*d)) / denominator;
        float imaginary = ((b*c) - (a*d)) / denominator;
         System.out.println("The division of complex number is "+ real + " + "+ imaginary + " i ");
    }
}

class complex {
    public static void main(String[] args) {
        float x;
        float y;
        Scanner in = new Scanner(System.in);
         System.out.println("Enter the real part of first complex number : ");
         x = in.nextFloat();
         System.out.println("Enter the Imaginary part of first complex number : ");
         y = in.nextFloat();
        ComplexNumber obj1 = new ComplexNumber(x , y);
        ComplexNumber obj2 = new ComplexNumber();
        int a;
        while(true){
            System.out.println("(1) Addition of complex numbers");
            System.out.println("(2) Substraction of complex numbers");
            System.out.println("(3) Multiplication of complex numbers");
            System.out.println("(4) Division of complex numbers");
            System.out.println("(5) Exit");
            a = in.nextInt();
            if(a==1)  obj1.add(obj1,obj2);
            else if(a==2)  obj1.sub(obj1,obj2);
            else if(a==3)  obj1.mul(obj1,obj2);
            else if(a==4)  obj1.divide(obj1,obj2);
            else break;
        }
    }
}