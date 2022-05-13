
import java.util.Scanner;

class WeatherReport{
    float highTemp;
    float lowTemp;
    float amountRain;
    float amountSnow;
    String date;
    String city;
    
    WeatherReport(){
        getData();
    }
    WeatherReport(float high , float low, float rain ,float snow , String day , String name ){
        highTemp = high;
        lowTemp = low;
        amountRain = rain;
        amountSnow = snow;
        date = day;
        city = name;
    }
    void getData(){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the date : ");
        date = sc.nextLine();
        System.out.println("Enter the city name : ");
        city = sc.nextLine();
        System.out.println("Enter the Highest Temperature : ");
        highTemp = sc.nextFloat();
        System.out.println("Enter the Lowest Temperature : ");
        lowTemp = sc.nextFloat();
        System.out.println("Enter the Amount of Rain : ");
        amountRain = sc.nextFloat();
        System.out.println("Enter the Amount of Snow : ");
        amountSnow = sc.nextFloat();
    }
    void printData(){
        System.out.println("Date\t\t CityName\t HighestTemperature\t LowestTemperature\t Amount of Rain\t Amount of Snow\t");
        System.out.println(date + "\t " + city + "\t\t\t" + highTemp + "\t\t\t" + lowTemp + "\t\t\t" + amountRain + "\t\t" + amountSnow);
    }
}



public class weather1 {
    public static void main(String[] args) {
        System.out.println("Enter the details for weather report : ");
        WeatherReport[] arr;
        arr = new WeatherReport[5];
        float highTemp;
        float lowTemp;
        float amountRain;
        float amountSnow;
        String date;
        String city;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the date : ");
        date = sc.nextLine();
        System.out.println("Enter the city name : ");
        city = sc.nextLine();
        System.out.println("Enter the Highest Temperature : ");
        highTemp = sc.nextFloat();
        System.out.println("Enter the Lowest Temperature : ");
        lowTemp = sc.nextFloat();
        System.out.println("Enter the Amount of Rain : ");
        amountRain = sc.nextFloat();
        System.out.println("Enter the Amount of Snow : ");
        amountSnow = sc.nextFloat();
        arr[0] = new WeatherReport(highTemp , lowTemp , amountRain , amountSnow , date , city);
        for(int i=1;i<5;i++){
            arr[i] = new WeatherReport();
        }
        System.out.println("Weather Report");
        for(int i=0;i<5;i++){
            arr[i].printData();
        }
    }
}
