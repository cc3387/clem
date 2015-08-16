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
        
        var loc_lng: String = String(format:"%f",register_info.location_lng);
        var loc_lat:String = String(format:"%f",register_info.location_lat);
        
    var params = [
        "title": register_info.user_id,
        "user_id": register_info.user_id,
        "Age_Range": register_info.age_range,
        "location": register_info.location,
        "Gender": register_info.Gender,
        "longitude": loc_lng,
        "latitude": loc_lat,
        "Education":register_info.education,
        "Major":register_info.Major
        ];
        
        manager.POST("http://localhost:3000/reg_test1",
            parameters: params,
            success: { (AFHTTPRequestOperation, AnyObject) -> Void in
                println("success!")
            }) { (AFHTTPRequestOperation, NSError) -> Void in
                println("fail")
        }
        
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
        ["Anthropology", "Psychology", "Mathematics", "Physics", "Economics", "Electrical Engineering"]
    ]
    
    func pickerView(pickerView: UIPickerView, numberOfRowsInComponent component: Int) -> Int {
        return pickerData[component].count
    }
    
    func pickerView(pickerView: UIPickerView, titleForRow row: Int, forComponent component: Int) -> String! {
        return pickerData[component][row]
    }
    
}
