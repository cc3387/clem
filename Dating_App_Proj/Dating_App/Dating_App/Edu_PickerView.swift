//
//  Edu_PickerView.swift
//  Simple
//
//  Created by Clement Chan on 7/26/15.
//  Copyright (c) 2015 Clement Chan. All rights reserved.
//

import Foundation

import UIKit

class Edu_PickerView: UIViewController,UIPickerViewDataSource, UIPickerViewDelegate {
    
    @IBOutlet weak var myPicker: UIPickerView!
    
    var Edu: String = "";
    
    override func viewDidLoad() {
        super.viewDidLoad()
        myPicker.delegate = self;
        myPicker.dataSource = self;
        // Do any additional setup after loading the view, typically from a nib.
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    @IBAction func Nextquest(sender: AnyObject) {
        updateLoc();
        loadDestinationVC();
    }
    
    enum PickerComponent:Int{
        case loc = 0
    }
    
    func updateLoc(){
        var sizeComponent = PickerComponent.loc.rawValue
        let size = pickerData[sizeComponent][myPicker.selectedRowInComponent(sizeComponent)]
        self.Edu = size;
        register_info.education = self.Edu;
        println(register_info.education);
    }
    
    
    func numberOfComponentsInPickerView(pickerView: UIPickerView) -> Int {
        return pickerData.count
    }
    
    let pickerData = [
        ["Princeton","Harvard","Yale","Columbia", "Oxford", "Cambridge", "Stanford", "U of Chicago", "MIT", "Duke", "UPenn", "Cal Tech", "Dartmouth", "John Hopkins", "Norwestern", "Washing Uni St.Louis", "Cornell", "Brown", "Notre Dame", "King's College London", "Vanderbuilt","Rice University", "UC Berkeley","Emory", "UT Austin", "Tokyo U", "Tsinghua U", "Beijing U", "Kyoto U", "Boston U", "Syracus", "U of Maryland", "Imperial College",
            "LSE", "UCL", "Georgetown","UCLA","UVA","CMU","USC","Tufts","Wake Forest","UMich--Ann Arbor", "Warwick", "HKU", "HKUST", "CUHK","Bath U","UNC-Chapel Hill", "Boston College", "NYU","William and Mary", "Brandeis", "U of Rochester", "UCSD","Lehigh", "UC Irvine", "U of Illinois-Urbana-Champaign","U of Wisconsin-Madison", "U of Washington", "U of Miami", "Penn State", "Other"]
    ]
    
    func pickerView(pickerView: UIPickerView, numberOfRowsInComponent component: Int) -> Int {
        return pickerData[component].count
    }
    
    func pickerView(pickerView: UIPickerView, titleForRow row: Int, forComponent component: Int) -> String! {
        return pickerData[component][row]
    }
    
    func loadDestinationVC(){
        self.performSegueWithIdentifier("Major", sender: nil)
    }
    
    /*Function to change the color of the fonts in the pickerview*/
    
    func pickerView(pickerView: UIPickerView, viewForRow row: Int, forComponent component: Int, reusingView view: UIView!) -> UIView
    {
        var pickerLabel = UILabel()
        pickerLabel.textColor = UIColor.whiteColor()
        pickerLabel.text = pickerData[component][row]
        // pickerLabel.font = UIFont(name: pickerLabel.font.fontName, size: 15)
        pickerLabel.font = UIFont(name: "System Thin", size: 20) // In this use your custom font
        pickerLabel.textAlignment = NSTextAlignment.Center
        return pickerLabel
    }
    
}
