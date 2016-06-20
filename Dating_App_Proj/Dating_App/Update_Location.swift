//
//  Google_Location.swift
//  Simple
//
//  Created by Clement Chan on 8/9/15.
//  Copyright (c) 2015 Clement Chan. All rights reserved.
//

import UIKit
import Firebase

class Google_ViewController_Update: UIViewController, CLLocationManagerDelegate, GMSMapViewDelegate {
    
    @IBOutlet weak var Address: UITextField!
    
    var mapTasks = MapTasks();
    
    @IBAction func Request_From_Text(sender: AnyObject) {
        
        let address = self.Address.text;
        
        register_info.address = address!;
        
        self.mapTasks.getLatLngForZip(register_info.address);
        
        let coordinate = CLLocationCoordinate2D(latitude: self.mapTasks.fetchedAddressLatitude, longitude: self.mapTasks.fetchedAddressLongitude)

        var NameRef = Firebase(url: "https://simpleplus.firebaseio.com/users/" + login_user.user_name)
                
        var location = [
            "longitude": self.mapTasks.fetchedAddressLongitude,
            "latitude": self.mapTasks.fetchedAddressLatitude
        ];
                
        NameRef.updateChildValues(location);

        
        self.loadDestinationVC();
    }
    
    override func viewDidLoad() {
        self.navigationController?.interactivePopGestureRecognizer?.enabled = false
        self.navigationController?.setNavigationBarHidden(true, animated: false)
        // Do any additional setup after loading the view, typically from a nib.
    }
    
    override func didReceiveMemoryWarning() {
        // Dispose of any resources that can be recreated.
    }
    
    
    func loadDestinationVC(){
        self.performSegueWithIdentifier("Update_Main_Page", sender: nil)
    }
    
}