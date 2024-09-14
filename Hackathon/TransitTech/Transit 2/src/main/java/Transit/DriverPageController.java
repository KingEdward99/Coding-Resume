package Transit;

import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.chrome.ChromeDriver;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;


@Controller
@RequestMapping("/driver")
public class DriverPageController {

    @Autowired
    private RidersRepository ridersRepository;

    @GetMapping
    public ResponseEntity<List<Rider>> returnAllRiders(){

////        ArrayList<String> addressList = new ArrayList<String>();
////
////        ArrayList<Rider> riderList = ridersRepository.findAll();
////
////        for(int count = 0; count < riderList.size(); count++) {
////            addressList.add(riderList.get(count).getStartAddress());
////        }
////
////        return addressList;
//
//        ArrayList<Rider> riderList = ridersRepository.findAll();
//
//        System.setProperty("webdriver.chrome.driver", "/home/chris/Documents/chromedriver_linux64/chromedriver");
//        WebDriver driver = new ChromeDriver();
//        driver.get("https://www.google.com/maps/dir///@39.3416519,-76.5839185,14z/data=!4m2!4m1!3e0");
//
//        //add first addresses
//        driver.findElement(By.xpath("//div/input[@class='tactile-searchbox-input' and starts-with(@aria-label, 'Choose') ]")).sendKeys(riderList.get(0).getStartAddress());
//        //driver.findElement(By.xpath("//*[@id='sb_ifc50']/input")).sendKeys(riderList.get(0).getStartAddress());
//
//        //add second address
//        driver.findElement(By.xpath("//div/input[@class='tactile-searchbox-input' and starts-with(@aria-label, 'Choose') ]")).sendKeys(riderList.get(1).getStartAddress());
//        //driver.findElement(By.xpath("//*[@id='sb_ifc51']/input")).sendKeys(riderList.get(1).getStartAddress());
//
//
//
//
//        //for all other addresses in the list click the add destination button then
//        for(int count = 2; count < riderList.size(); count++) {
//            //click add one more destination button
//            driver.findElement(By.xpath("//*[@id='omnibox-directions']/div/div[3]/button")).click();
//
//            //send address to newly generated text block
//            driver.findElement(By.xpath("//div/input[@class='tactile-searchbox-input' and starts-with(@aria-label, 'Choose') ]")).sendKeys(riderList.get(count).getStartAddress() + "\n");
//        }
//        //div/input[@class="tactile-searchbox-input" and starts-with(@aria-label, 'Choose') ]


        return new ResponseEntity<List<Rider>>(ridersRepository.findAll(), HttpStatus.OK);
    }





}
