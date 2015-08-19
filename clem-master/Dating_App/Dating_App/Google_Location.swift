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
            println("The Latitude is:");
            println(register_info.location_lat);
            println("The Longitude is:");
            println(register_info.location_lng);
            
            /*Sending Location latitude and longitude to the localhost server*/
                
            var loc_lng:String = String(format:"%f",register_info.location_lng);
            var loc_lat:String = String(format:"%f",register_info.location_lat);
                
                
            var params = [
            "longitude": loc_lng,
            "latitude" : loc_lat
            ];
                
            let manager = AFHTTPRequestOperationManager();
                
            manager.POST("http://localhost:3000/location",
            parameters: params,
            success: { (AFHTTPRequestOperation, AnyObject) -> Void in
            println("success!")
            }) { (AFHTTPRequestOperation, NSError) -> Void in
            println("fail")
            }
                
            }
         
        })
        
        self.loadDestinationVC();
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
        /*Sending the latitude and longitude information to the server*/

        var params = [
            "longitude": register_info.location_lng,
            "latitude" : register_info.location_lat
        ];
        
        let manager = AFHTTPRequestOperationManager();
        
        manager.POST("http://localhost:3000/clem",
            parameters: params,
            success: { (AFHTTPRequestOperation, AnyObject) -> Void in
                println("success!")
            }) { (AFHTTPRequestOperation, NSError) -> Void in
                println("fail")
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
    
    
    func loadDestinationVC(){
        self.performSegueWithIdentifier("Gender", sender: nil)
    }

}