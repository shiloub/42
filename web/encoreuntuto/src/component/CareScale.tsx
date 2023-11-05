interface CareScaleProps {
    scaleValue: number
    type: string
    onClick: any
}
export default function CareScale({scaleValue, type, onClick}: CareScaleProps) {
    const emo = type === "sun" ? "☀️" : "💧"
    const range = [1, 2, 3];

    return (
        <div onClick={() => {onClick(type, scaleValue)}}>
            {range.map((rangeValue) => (
                scaleValue >= rangeValue ? <span key={rangeValue}>{emo}</span> : null
            ))}
        </div>
    )
}
