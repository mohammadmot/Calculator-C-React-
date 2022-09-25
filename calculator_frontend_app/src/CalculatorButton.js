import React from 'react'

// CalculatorButton component
function CalculatorButton(props) {
    return (
        <input
            type='button'
            value={props.caption}
            className={props.caption === "=" ? "calculator-equal-button" : null}
            onClick={props.onClick} />
    );
}

// to visible outside
export default CalculatorButton;