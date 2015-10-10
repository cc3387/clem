//
//  Final_Send.swift
//  Simple
//
//  Created by Clement Chan on 9/4/15.
//  Copyright (c) 2015 Clement Chan. All rights reserved.
//

import Foundation
import UIKit

class FinalSend: UIViewController{
    
    @IBOutlet weak var userid: UILabel!
    @IBOutlet weak var Profile_Name: UILabel!
    @IBOutlet weak var City: UILabel!
    @IBOutlet weak var Address: UILabel!
    @IBOutlet weak var Gender: UILabel!
    @IBOutlet weak var School: UILabel!
    @IBOutlet weak var Major: UILabel!
    
    @IBAction func ConfirmSend(sender: AnyObject) {
        
        let manager = AFHTTPRequestOperationManager();
        
        var loc_lng_int = round(register_info.location_lng);
        var loc_lat_int = round(register_info.location_lat);
        
        var loc_lng: String = String(format:"%f",register_info.location_lng);
        var loc_lat:String = String(format:"%f",register_info.location_lat);
        
        //var loc_lng: String = String(format:"%f",loc_lng_int);
        //var loc_lat:String = String(format:"%f",loc_lat_int);
        
        var params = [
            "title": register_info.user_id,
            "user_id": register_info.user_id,
            "Profile_Name": register_info.Profile_name,
            "Age_Range": register_info.age_range,
            "location": register_info.location,
            "Gender": register_info.Gender,
            "Ethnicity": register_info.Ethnicity,
            "longitude": loc_lng,
            "latitude": loc_lat,
            "Education":register_info.education,
            "Major":register_info.Major,
            "Address": register_info.address,
            "Beer_Wine": register_info.beer_or_wine,
            "Sports_Art": register_info.sports_or_art,
            "Cooking_DineOut": register_info.Cooking_Dineout
        ];
        
        manager.POST("http://localhost:3000/database",
            parameters: params,
            success: { (AFHTTPRequestOperation, AnyObject) -> Void in
                println("success!")
            }) { (AFHTTPRequestOperation, NSError) -> Void in
                println("fail")
        }
        
        /*var param_loc = [
            "title": register_info.location,
            "longitude": loc_lng,
            "latitude": loc_lat,
            "Address": register_info.address,
            "user_id": register_info.user_id,
            "Profile_Name": register_info.Profile_name
        ];
        
        
        manager.POST("http://localhost:3000/collections/loc_reg1",
            parameters: param_loc,
            success: { (AFHTTPRequestOperation, AnyObject) -> Void in
                println("success!")
            }) { (AFHTTPRequestOperation, NSError) -> Void in
                println("fail")
        }
        
        let cityurl = "http://localhost:3000/collections/city1" + "_" + register_info.location;
        
        println(cityurl);
        
        manager.POST(cityurl,
            parameters: param_loc,
            success: { (AFHTTPRequestOperation, AnyObject) -> Void in
                println("success!")
            }) { (AFHTTPRequestOperation, NSError) -> Void in
                println("fail")
        }*/
        
        
        loadDestinationVC();
        
        
    }
    
    override func viewDidLoad() {
        // Do any additional setup after loading the view, typically from a nib.
        self.userid.text = register_info.user_id
        self.City.text = register_info.location
        self.Gender.text = register_info.Gender
        self.School.text = register_info.education
        self.Major.text = register_info.Major
        self.Profile_Name.text = register_info.Profile_name
        self.userid.adjustsFontSizeToFitWidth = true
        self.City.adjustsFontSizeToFitWidth = true
        self.Gender.adjustsFontSizeToFitWidth = true
        self.School.adjustsFontSizeToFitWidth = true
        self.Major.adjustsFontSizeToFitWidth = true
        self.Profile_Name.adjustsFontSizeToFitWidth = true
    }
    
    override func didReceiveMemoryWarning() {
        // Dispose of any resources that can be recreated.
    }
    
    
    func loadDestinationVC(){
        self.performSegueWithIdentifier("Start", sender: nil)
    }
    
}

