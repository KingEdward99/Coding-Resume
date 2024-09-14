/*
 * Adding a new rider to the database 
 * 
 * Name: Eddy Koundjou Yem 
 * Date: September 14, 2024
 */

 // necessary packages
package Transit;

//necessary imports 
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import java.util.Map;

@Controller
@RequestMapping("/rider")
public class RiderPageController {

    @Autowired
    RidersRepository ridersRepository;

    @GetMapping
    public String showRiderView(Model model) {
        model.addAttribute("rider", new Rider());
        return "riderView";
    }

    @PostMapping
    public ResponseEntity<Rider> createRider(@RequestBody Map<String, String> payload) {

        return new ResponseEntity<Rider>(ridersRepository.insert(new Rider(payload.get("startAddress"))), HttpStatus.CREATED);
    }

}
