# EPAM-SYSTEM-ASSIGNMENT-1
A responsive web app for XYZ Bank's Diwali coupon promo. Users register, enter a customer ID, and validate it against records with real-time feedback. Once validated, they generate a unique coupon code. Built with clean HTML, CSS (mobile-responsive), and JS handling step-by-step logic and input state.

## Web Page Overview — with Technology Details

**Project Name:** XYZ Bank – Diwali Coupon Registration Portal

**Purpose:** A promotional customer-facing web page that lets bank customers verify their identity and claim a Diwali festival discount coupon through a guided, three-step interactive process — without needing a backend or page reload.

**Type:** Front-end only, single-page interactive form

| Aspect | Details |
|---|---|
| **Project Type** | Static, client-side web application (no backend/database) |
| **Target Users** | XYZ Bank customers accessing a seasonal promotional campaign |
| **Core Goal** | Validate a customer's identity and issue a unique coupon code |
| **File Structure** | `index.html` (markup), `style.css` (styling), `app.js` (logic) |
| **Design Approach** | Mobile-first, responsive layout using flexbox and media queries |
| **State Management** | Simple JS boolean flag (`isValidated`) to control access to coupon generation |
| **Data Source** | Hardcoded demo array (`knownCustomers`) simulating a customer database |
| **User Interaction Model** | Progressive disclosure — sections reveal only as the user completes each step |

## Technology Stack

| Layer | Technology | Version/Standard | Role in Project |
|---|---|---|---|
| Structure | HTML5 | Living Standard | Defines page content, form elements, semantic layout |
| Styling | CSS3 | Level 3/4 features (Flexbox, `clamp()`, media queries) | Handles visual design and responsive behavior |
| Logic/Interactivity | JavaScript (ES6+) | Vanilla JS, no framework | Handles DOM manipulation, event listeners, validation logic |
| Layout Engine | CSS Flexbox | `display: flex` | Powers the button row layout and responsive stacking |
| Responsive Technique | CSS Media Queries | `@media (max-width: 480px)` | Adapts layout for mobile screens |
| Fluid Typography | CSS `clamp()` | Native CSS function | Scales heading size smoothly across viewport widths |
| Pattern Matching | JavaScript Regular Expressions | `/^[A-Za-z0-9]{4,12}$/` | Validates customer ID format |
| Random Generation | JavaScript `Math.random()` | Native JS | Generates unique coupon codes |
| Browser APIs Used | DOM API | `document.getElementById`, `addEventListener`, `classList` | Element selection and event handling |
| Font | Georgia / Times New Roman (system serif) | Web-safe fonts | Typography, no external font loading required |

## Why This Stack Was Chosen

| Reason | Explanation |
|---|---|
| No dependencies | Pure HTML/CSS/JS means zero build tools, npm packages, or frameworks — loads instantly |
| Lightweight | Small file sizes make it fast on any connection, including mobile banking users |
| Framework-agnostic foundation | Easy to later migrate into React/Vue/Angular or integrate into an existing bank portal |
| Wide browser compatibility | Vanilla JS + standard CSS3 features work across all modern browsers without polyfills |
| Easy backend integration path | The `fetch()` API can be dropped into `app.js` later to replace the hardcoded array with a real REST API call |
