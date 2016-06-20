//
//  Ethnicity_PickerView.swift
//  Simple
//
//  Created by Clement Chan on 9/30/15.
//  Copyright (c) 2015 Clement Chan. All rights reserved.
//

import Foundation


import UIKit

class Ethinicity_PickerView: UIViewController,UIPickerViewDataSource, UIPickerViewDelegate {
    
    @IBOutlet weak var myPicker: UIPickerView!
    
    var Ethnic: String = "";
    
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
        self.Ethnic = size;
        register_info.Ethnicity = self.Ethnic;
        print(register_info.Ethnicity);
    }
    
    
    func numberOfComponentsInPickerView(pickerView: UIPickerView) -> Int {
        return pickerData.count
    }
    
    let pickerData = [
        ["White", "Black or African American", "American Indian", "Asian", "Native Hawaiian", "Nonresident Alien"]
    ]
    
    func pickerView(pickerView: UIPickerView, numberOfRowsInComponent component: Int) -> Int {
        return pickerData[component].count
    }
    
    func pickerView(pickerView: UIPickerView, titleForRow row: Int, forComponent component: Int) -> String! {
        return pickerData[component][row]
    }
    
    func loadDestinationVC(){
        self.performSegueWithIdentifier("Education", sender: nil)
    }
    
    /*Function to change the color of the fonts in the pickerview*/
    
    func pickerView(pickerView: UIPickerView, viewForRow row: Int, forComponent component: Int, reusingView view: UIView!) -> UIView
    {
        var pickerLabel = UILabel()
        pickerLabel.textColor = UIColor.whiteColor()
        pickerLabel.text = pickerData[component][row]
        pickerLabel.font = UIFont(name: pickerLabel.font.fontName, size: 12)
        //pickerLabel.font = UIFont(name: "System Thin", size: 13) // In this use your custom font
        pickerLabel.textAlignment = NSTextAlignment.Center
        return pickerLabel
    }
    
}
