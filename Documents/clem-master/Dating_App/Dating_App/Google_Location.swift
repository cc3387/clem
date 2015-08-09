//
//  Google_Location.swift
//  Simple
//
//  Created by Clement Chan on 8/9/15.
//  Copyright (c) 2015 Clement Chan. All rights reserved.
//

import UIKit

class Google_ViewController: UIViewController, CLLocationManagerDelegate, GMSMapViewDelegate {
    
    @IBOutlet weak var Address: UITextField!
    
    var mapTasks = MapTasks();
    
    @IBAction func Request_From_Text(sender: AnyObject) {
        
        let address = self.Address.text;
        
        self.mapTasks.geocodeAddress(address, withCompletionHandler: { (status, success) -> Void in
            
            if !success {
            println(status)
            
            if status == "ZERO_RESULTS" {
            println("The location could not be found.")
            }
            }
            else {
            let coordinate = CLLocationCoordinate2D(latitude: self.mapTasks.fetchedAddressLatitude, longitude: self.mapTasks.fetchedAddressLongitude)
            register_info.location_lat = self.mapTasks.fetchedAddressLatitude;
            register_info.location_lng = self.mapTasks.fetchedAddressLongitude;
            println(register_info.location_lat);
            println(register_info.location_lng);
            }
        
        })
    }
    
    
    
    
    @IBAction func Request_Address(sender: AnyObject) {
        
        let addressAlert = UIAlertController(title: "Address Finder", message: "Please type your address:", preferredStyle: UIAlertControllerStyle.Alert)
        
        addressAlert.addTextFieldWithConfigurationHandler { (textField) -> Void in
            textField.placeholder = "Address?"
        }
        
        let findAction = UIAlertAction(title: "Find Address", style: UIAlertActionStyle.Default) { (alertAction) -> Void in
            let address = (addressAlert.textFields![0]as! UITextField).text as String
        
            self.mapTasks.geocodeAddress(address, withCompletionHandler: { (status, success) -> Void in
                if !success {
                    println(status)
                    
                    if status == "ZERO_RESULTS" {
                    println("The location could not be found.")
                    }
                }
                else {
                    let coordinate = CLLocationCoordinate2D(latitude: self.mapTasks.fetchedAddressLatitude, longitude: self.mapTasks.fetchedAddressLongitude)
                    register_info.location_lat = self.mapTasks.fetchedAddressLatitude;
                    register_info.location_lng = self.mapTasks.fetchedAddressLongitude;
                    println(register_info.location_lat);
                    println(register_info.location_lng);
                }
            })
            
        }
        
        let closeAction = UIAlertAction(title: "Close", style: UIAlertActionStyle.Cancel) { (alertAction) -> Void in
            
        }
        
        addressAlert.addAction(findAction)
        addressAlert.addAction(closeAction)
        
        presentViewController(addressAlert, animated: true, completion: nil)
    }
    
    override func viewDidLoad() {
        // Do any additional setup after loading the view, typically from a nib.
    }
    
    override func didReceiveMemoryWarning() {
        // Dispose of any resources that can be recreated.
    }

}