//
//  Distance_Calculation.swift
//  Simple
//
//  Created by Clement Chan on 8/23/15.
//  Copyright (c) 2015 Clement Chan. All rights reserved.
//

import Foundation

class Distance_Calculation: UIViewController{
    
    @IBOutlet weak var Origin: UILabel!
    @IBOutlet weak var Destination: UILabel!
    @IBOutlet weak var Duration: UILabel!
    
    var travel_mode = TravelModes.driving;
    
    @IBAction func Distance_Calc(sender: AnyObject) {
        
        let manager = AFHTTPRequestOperationManager();
        
        
        manager.GET( "http://localhost:3000/loc_reg2/location/NY",
            parameters: nil,
            success: { (operation: AFHTTPRequestOperation!,responseObject: AnyObject!) in
                println("JSON: " + responseObject.description)
                println("Object obtained successfully");
                println(responseObject.count);
                
                if let results = responseObject[0] as? NSDictionary {
                    if let Address = results["Address"] as? String {
                        self.Origin.text = Address as String
                        self.Origin.adjustsFontSizeToFitWidth = true
                    }
                }
            },
            failure: { (operation: AFHTTPRequestOperation!,error: NSError!) in
                println("Error: " + error.localizedDescription)
            }
        )
        
        manager.GET( "http://localhost:3000/loc_reg2/location/NY",
            parameters: nil,
            success: { (operation: AFHTTPRequestOperation!,responseObject: AnyObject!) in
                println("JSON: " + responseObject.description)
                println("Object obtained successfully");
                println(responseObject.count);
                
                if let results = responseObject[1] as? NSDictionary {
                    if let Address = results["Address"] as? String {
                        self.Destination.text = Address as String
                        self.Destination.adjustsFontSizeToFitWidth = true
                    }
                }
            },
            failure: { (operation: AFHTTPRequestOperation!,error: NSError!) in
                println("Error: " + error.localizedDescription)
            }
        )
    }
    
    
    @IBAction func Time_Distance(sender: AnyObject) {
        
        var maptasks = MapTasks();
        
        maptasks.getDirections(self.Origin.text, destination: self.Destination.text, waypoints: nil, travelMode: self.travel_mode, completionHandler: { (status, success) -> Void in
            if success {
                println("Successfully found directions");
                self.Duration.text = maptasks.totalDuration;
                self.Duration.adjustsFontSizeToFitWidth = true
            }
            else {
                println(status)
            }
        })
        
        
    }

    override func viewDidLoad() {
        
        // Do any additional setup after loading the view, typically from a nib.
    }
    
    override func didReceiveMemoryWarning() {
        // Dispose of any resources that can be recreated.
    }
}