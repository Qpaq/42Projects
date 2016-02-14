//
//  MoreViewController.swift
//  RushSwift
//
//  Created by David TEDGUI on 2/13/16.
//  Copyright © 2016 David TEDGUI. All rights reserved.
//

import UIKit
import MapKit

class MoreViewController: UIViewController {
	
	var settingsMapType: MKMapType = .Satellite

	
	var delegateMapViewController: MapViewController!
	var delegateListViewController: ListTableViewController!
	
    override func viewDidLoad() {
        super.viewDidLoad()
		delegateMapViewController = self.tabBarController?.viewControllers![0] as! MapViewController
		let nav = self.tabBarController?.viewControllers![1] as! UINavigationController
		delegateListViewController = nav.viewControllers[0] as! ListTableViewController
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
    }
    
    
    @IBAction func settingsMapType(sender: AnyObject) {
		switch sender.selectedSegmentIndex {
			case 0:
				settingsMapType = .Standard
			case 1:
				settingsMapType = .Satellite
			case 2:
				settingsMapType = .Hybrid
			default:
				settingsMapType = .Satellite
		}
		
		delegateMapViewController.currentMapType = settingsMapType
		delegateListViewController.settingsMapType = settingsMapType
		
    }
	
	
}