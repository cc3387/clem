//
//  Edu_PickerView.swift
//  Simple
//
//  Created by Clement Chan on 7/26/15.
//  Copyright (c) 2015 Clement Chan. All rights reserved.
//

import Foundation

import UIKit

class Edu_PickerView_UK: UIViewController,UIPickerViewDataSource, UIPickerViewDelegate {
    
    
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
        [
            "University of Cambridge",
            "University of Oxford",
            "University of St Andrews",
            "Imperial College London",
            "London School of Economics",
            "Durham University",
            "University of Exeter",
            "University of Warwick",
            "University College London",
            "University of Bath",
            "University of Surrey",
            "Lancaster University",
            "Loughborough University",
            "University of East Anglia",
            "University of Birmingham",
            "University of York",
            "University of Leeds",
            "University of Southampton",
            "University of Bristol",
            "University of Leicester",
            "University of Sheffield",
            "University of Edinburgh",
            "Newcastle University",
            "University of Nottingham",
            "University of Sussex",
            "University of Glasgow",
            "Cardiff University",
            "University of Manchester",
            "King's College London",
            "University of Kent",
            "SOAS, University of London",
            "University of Essex",
            "University of Reading",
            "Aston University",
            "Royal Holloway, University of London",
            "University of Liverpool",
            "Queen Mary, University of London",
            "Queen's University Belfast",
            "University of Strathclyde",
            "Keele University",
            "Heriot-Watt University",
            "Coventry University",
            "Swansea University",
            "University of Aberdeen",
            "University of Dundee",
            "City University London",
            "Brunel University",
            "University of Buckingham",
            "Oxford Brookes University",
            "Bangor University",
            "Falmouth University",
            "Nottingham Trent University",
            "University of the Arts London",
            "Other"
            ]
    ]
    
    func pickerView(pickerView: UIPickerView, numberOfRowsInComponent component: Int) -> Int {
        return pickerData[component].count
    }
    
    func pickerView(pickerView: UIPickerView, titleForRow row: Int, forComponent component: Int) -> String! {
        return pickerData[component][row]
    }
    
    func loadDestinationVC(){
        self.performSegueWithIdentifier("Major_UK", sender: nil)
    }
    
    /*Function to change the color of the fonts in the pickerview*/
    
    func pickerView(pickerView: UIPickerView, viewForRow row: Int, forComponent component: Int, reusingView view: UIView!) -> UIView
    {
        var pickerLabel = UILabel()
        pickerLabel.textColor = UIColor.whiteColor()
        pickerLabel.text = pickerData[component][row]
        // pickerLabel.font = UIFont(name: pickerLabel.font.fontName, size: 15)
        pickerLabel.font = UIFont(name: "System Thin", size: 12) // In this use your custom font
        pickerLabel.textAlignment = NSTextAlignment.Center
        return pickerLabel
    }
    
}
