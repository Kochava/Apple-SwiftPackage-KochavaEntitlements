
import XCTest

@testable import KochavaEntitlements



final class KochavaEntitlementsTests: XCTestCase
{
    
    
    
    func test_register()
    {
        KVALog.shared.level = .trace
        
        KVAEntitlementsProduct.shared.register()
    }

    
    
    static var allTests =
    [
        ("test_register", test_register),
    ]
    
    
    
}



