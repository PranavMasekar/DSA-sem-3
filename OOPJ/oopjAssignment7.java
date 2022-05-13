import java.util.Scanner;

interface vehicle {
    final Scanner sc = new Scanner(System.in);
    abstract void changeGear(int gear);
    abstract void speedUp(int speed);
    abstract void applyBreak(int speed);
}

class Bicycle implements vehicle {
    int currentGear, currentSpeed;
    Bicycle() {
        getData();
    }
    void getData() {
        System.out.println("Enter the current gear of Bicycle: ");
        currentGear = sc.nextInt();
        System.out.println("Enter the current speed of Bicycle: ");
        currentSpeed = sc.nextInt();
    }
    @Override
    public void speedUp(int speed) {
        currentSpeed += speed;
        display();
    }
    @Override
    public void applyBreak(int speed) {
        currentSpeed -= speed;
        display();
    }
    @Override
    public void changeGear(int gear) {
        currentGear = gear;
        display();
    }
    void display() {
        System.out.println("Current gear of Bicycle is : " + currentGear);
        System.out.println("Current speed of Bicycle is : " + currentSpeed);
    }
}

class Bike implements vehicle {
    int currentGear, currentSpeed;
    Bike() {
        getData();
    }
    void getData() {
        System.out.println("Enter the current gear of Bike : ");
        currentGear = sc.nextInt();
        System.out.println("Enter the current speed of Bike : ");
        currentSpeed = sc.nextInt();
    }
    public void speedUp(int speed) {
        currentSpeed += speed;
        display();
    }
    @Override
    public void applyBreak(int speed) {
        currentSpeed -= speed;
        display();
    }
    @Override
    public void changeGear(int gear) {
        currentGear = gear;
        display();
    }
    void display() {
        System.out.println("Current gear of Bike is : " + currentGear);
        System.out.println("Current speed of Bike is : " + currentSpeed);
    }
}

class Car implements vehicle {
    int currentGear, currentSpeed;
    Car() {
        getData();
    }
    void getData() {
        System.out.println("Enter the current gear of Car : ");
        currentGear = sc.nextInt();
        System.out.println("Enter the current speed of Car : ");
        currentSpeed = sc.nextInt();
    }
    public void speedUp(int speed) {
        currentSpeed += speed;
        display();
    }
    @Override
    public void applyBreak(int speed) {
        currentSpeed -= speed;
        display();
    }
    @Override
    public void changeGear(int gear) {
        currentGear = gear;
        display();
    }
    void display() {
        System.out.println("Current gear of Car is : " + currentGear);
        System.out.println("Current speed of Car is : " + currentSpeed);
    }
}

class oopjAssignment7 {
    static int getdata(){
        Scanner sc = new Scanner(System.in);
        int val = sc.nextInt();
        return val;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int choice;
        while (true) {
            System.out.println("1. Bike \n2. Car \n3. Bicycle \n4. Exit");
            choice = sc.nextInt();
            if (choice == 1) {
                Bike obj = new Bike();
                int operation;
                while (true) {
                    System.out.println("1. ChangeGear \n2. SpeedUp \n3. ApplyBreak \n4. Exit");
                    operation = sc.nextInt();
                    if (operation == 1) {
                        System.out.println("Enter Gear");
                        obj.changeGear(getdata());
                    } else if (operation == 2) {
                        System.out.println("Enter Speed");
                        obj.speedUp(getdata());
                    } else if (operation == 3) {
                        System.out.println("Enter Speed");
                        obj.applyBreak(getdata());
                    } 
                    else if(operation==4) break;
                    else
                        System.out.println("Wrong choice");
                }
            } else if (choice == 2) {
                Car obj = new Car();
                int operation;
                while (true) {
                    System.out.println("1. ChangeGear \n2. SpeedUp \n3. ApplyBreak \n4. Exit");
                    operation = sc.nextInt();
                    if (operation == 1) {
                        System.out.println("Enter Gear");
                        obj.changeGear(getdata());
                    } else if (operation == 2) {
                        System.out.println("Enter Speed");
                        obj.speedUp(getdata());
                    } else if (operation == 3) {
                        System.out.println("Enter Speed");
                        obj.applyBreak(getdata());
                    } 
                    else if(operation==4) break;
                    else
                        System.out.println("Wrong choice");
                }
            } else if (choice == 3) {
                Bicycle obj = new Bicycle();
                int operation;
                while (true) {
                    System.out.println("1. ChangeGear \n2. SpeedUp \n3. ApplyBreak \n4. Exit");
                    operation = sc.nextInt();
                    if (operation == 1) {
                        System.out.println("Enter Gear");
                        obj.changeGear(getdata());
                    } else if (operation == 2) {
                        System.out.println("Enter Speed");
                        obj.speedUp(getdata());
                    } else if (operation == 3) {
                        System.out.println("Enter Speed");
                        obj.applyBreak(getdata());
                    } 
                    else if(operation==4) break;
                    else
                        System.out.println("Wrong choice");
                }
            } else if (choice == 4) {
                break;
            } else {
                System.out.println("Wrong choice");
            }

        }
    }
}