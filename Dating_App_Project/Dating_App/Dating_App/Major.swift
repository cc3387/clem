//
//  Major.swift
//  Simple
//
//  Created by Clement Chan on 7/27/15.
//  Copyright (c) 2015 Clement Chan. All rights reserved.
//

import Foundation
import UIKit

class Major: UIViewController,UIPickerViewDelegate,UIPickerViewDataSource{
    
    @IBOutlet weak var myPicker: UIPickerView!
    var Major = "";
    
    @IBAction func Info(sender: AnyObject) {
        
        self.updateMajor();
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
        "Age_Range": register_info.age_range,
        "location": register_info.location,
        "Gender": register_info.Gender,
        "longitude": loc_lng,
        "latitude": loc_lat,
        "Education":register_info.education,
        "Major":register_info.Major,
        "Address": register_info.address
        ];
        
        manager.POST("http://localhost:3000/collections/reg_test",
            parameters: params,
            success: { (AFHTTPRequestOperation, AnyObject) -> Void in
                println("success!")
            }) { (AFHTTPRequestOperation, NSError) -> Void in
                println("fail")
        }
     
    var param_loc = [
            "title": register_info.location,
            "longitude": loc_lng,
            "latitude": loc_lat,
            "Address": register_info.address,
            "user_id": register_info.user_id
        ];

        
        manager.POST("http://localhost:3000/collections/loc_reg",
            parameters: param_loc,
            success: { (AFHTTPRequestOperation, AnyObject) -> Void in
                println("success!")
            }) { (AFHTTPRequestOperation, NSError) -> Void in
                println("fail")
        }
        
        let cityurl = "http://localhost:3000/collections/city" + "_" + register_info.location;
        
        println(cityurl);
        
        manager.POST(cityurl,
            parameters: param_loc,
            success: { (AFHTTPRequestOperation, AnyObject) -> Void in
                println("success!")
            }) { (AFHTTPRequestOperation, NSError) -> Void in
                println("fail")
        }
        
        
        loadDestinationVC();

    }
    
    override func viewDidLoad() {
        // Do any additional setup after loading the view, typically from a nib.
        myPicker.delegate = self;
        myPicker.dataSource = self;
    }
    
    override func didReceiveMemoryWarning() {
        // Dispose of any resources that can be recreated.
    }
    
    enum PickerComponent:Int{
        case loc = 0
    }
    
    func updateMajor(){
        var sizeComponent = PickerComponent.loc.rawValue
        let size = pickerData[sizeComponent][myPicker.selectedRowInComponent(sizeComponent)]
        self.Major = size;
        register_info.Major = self.Major;
        println(register_info.Major);
    }
    
    func numberOfComponentsInPickerView(pickerView: UIPickerView) -> Int {
        return pickerData.count
    }

    let pickerData = [
        ["Anthropology", "Computer Sci.","Psychology", "Mathematics", "Physics", "Economics", "Electrial Engineering", "English", "History"]
    ]
    
    func pickerView(pickerView: UIPickerView, numberOfRowsInComponent component: Int) -> Int {
        return pickerData[component].count
    }
    
    func pickerView(pickerView: UIPickerView, titleForRow row: Int, forComponent component: Int) -> String! {
        return pickerData[component][row]
    }
    
    /*Function to change the color of the fonts in the pickerview*/
    
    func pickerView(pickerView: UIPickerView, viewForRow row: Int, forComponent component: Int, reusingView view: UIView!) -> UIView
    {
        var pickerLabel = UILabel()
        pickerLabel.textColor = UIColor.blackColor()
        pickerLabel.text = pickerData[component][row]
        // pickerLabel.font = UIFont(name: pickerLabel.font.fontName, size: 15)
        pickerLabel.font = UIFont(name: "Arial-BoldMT", size: 15) // In this use your custom font
        pickerLabel.textAlignment = NSTextAlignment.Center
        return pickerLabel
    }
    
    
    func loadDestinationVC(){
        self.performSegueWithIdentifier("Start", sender: nil)
    }
    
    
}
