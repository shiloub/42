import { useState } from 'react'
import '../styles/footer.css'

function Footer() {
	const [inputValue, setInputValue] = useState('')

    function handleInput(e: any) {
        setInputValue(e.target.value);
    }

    function handleBlur()
    {
        if (!inputValue.includes('@'))
            alert('email incorrect');
    }

	return (
		<footer className='lmj-footer'>
			<div className='lmj-footer-elem'>
				Pour les passionné·e·s de plantes 🌿🌱🌵
			</div>
			<div className='lmj-footer-elem'>Laissez-nous votre mail :
            <input 
                type='text'
                value={inputValue}
                onChange={handleInput}
                onBlur={handleBlur} />
            </div>
		</footer>
	)
}

export default Footer