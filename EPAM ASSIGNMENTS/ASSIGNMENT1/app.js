document.addEventListener('DOMContentLoaded', () => {
    const demo = document.getElementById('demo');
    const registerBtn = document.getElementById('register');
    const custSection = document.getElementById('custSection');
    const custIDInput = document.getElementById('custID');
    const validateBtn = document.getElementById('validate');
    const genCouponBtn = document.getElementById('genCoupon');
    const message = document.getElementById('message');
    const couponDisplay = document.getElementById('couponDisplay');

    let isValidated = false;

    // A simple mock list of "known" customer IDs for demo validation purposes
    const knownCustomers = ['CUST1001', 'CUST1002', 'CUST1234', 'DEMO001'];

    // Coupon button starts disabled until a customer is validated
    genCouponBtn.disabled = true;

    function showMessage(text, type) {
        message.textContent = text;
        message.className = 'message ' + (type || '');
    }

    // Step 3: Register hides the instructions and the register button itself
    registerBtn.addEventListener('click', () => {
        demo.style.display = 'none';
        registerBtn.style.display = 'none';
        custSection.style.display = 'block';
        showMessage('Registered! Enter your customer ID and validate to apply for coupons.', 'success');
    });

    // Step 1 & 2: Validate the customer ID
    validateBtn.addEventListener('click', () => {
        const custID = custIDInput.value.trim();

        if (!custID) {
            showMessage('Please enter a customer ID.', 'error');
            isValidated = false;
            genCouponBtn.disabled = true;
            return;
        }

        const idPattern = /^[A-Za-z0-9]{4,12}$/;
        if (!idPattern.test(custID)) {
            showMessage('Customer ID must be 4-12 letters/numbers, no spaces.', 'error');
            isValidated = false;
            genCouponBtn.disabled = true;
            return;
        }

        if (knownCustomers.includes(custID.toUpperCase())) {
            showMessage('Customer validated successfully. You can now generate your coupon.', 'success');
            isValidated = true;
            genCouponBtn.disabled = false;
        } else {
            showMessage('Customer ID not recognized. Please check and try again.', 'error');
            isValidated = false;
            genCouponBtn.disabled = true;
        }
    });

    // Generate a Diwali coupon code once validated
    genCouponBtn.addEventListener('click', () => {
        if (!isValidated) {
            showMessage('Please validate your customer ID first.', 'error');
            return;
        }

        const coupon = 'DIWALI-' + Math.random().toString(36).substring(2, 8).toUpperCase();
        couponDisplay.textContent = 'Your coupon code: ' + coupon;
        showMessage('Coupon generated! Happy Diwali.', 'success');
    });

    // Re-validate if the user edits the ID after a previous validation
    custIDInput.addEventListener('input', () => {
        if (isValidated) {
            isValidated = false;
            genCouponBtn.disabled = true;
        }
    });
});